#pragma once
#include <iostream>

template<class T>
class HeterogeneousContainer{
    T** objects = nullptr;
    size_t size, capacity = 0;

    void resize(size_t newCap);

	void copyFrom(const HeterogeneousContainer& other);
	void moveFrom(HeterogeneousContainer&& other) noexcept;
	void free();

    public:
    HeterogeneousContainer();
    HeterogeneousContainer(const HeterogeneousContainer& other);
    HeterogeneousContainer(const HeterogeneousContainer&& other) noexcept;

    HeterogeneousContainer<T>& operator=(const HeterogeneousContainer& other);
    HeterogeneousContainer<T>& operator= ( HeterogeneousContainer&& other) noexcept;

    ~HeterogeneousContainer();

    void addObject(T* obj);
    void addObject(const T& obj);

    void remove(size_t idx);

    size_t getSize() const;
    
    const T* operator[](size_t index) const;
	T* operator[](size_t index);
	void swap(int i, int j);
    

};

template <class T>
const T* HeterogeneousContainer<T>::operator[](size_t idx) const{
    if (idx >= size) {
		throw std::invalid_argument("Wrong index");
	}
    return  objects[idx];
}

template <class T>
T* HeterogeneousContainer<T>::operator[](size_t idx){
    if (idx >= size) {
		throw std::invalid_argument("Wrong index");
	}
    return objects[idx];
}
template<class T>
HeterogeneousContainer<T>:: HeterogeneousContainer(){
    objects = new T* [capacity] {};
}

template<class T>
HeterogeneousContainer<T>:: ~HeterogeneousContainer(){
    free();
}
template<class T> 
HeterogeneousContainer<T>:: HeterogeneousContainer(const HeterogeneousContainer& other){
    copyFrom(other);
}

template <class T>
HeterogeneousContainer<T>::HeterogeneousContainer(const HeterogeneousContainer&& other){
    moveFrom(move(other));
}

template<class T>
HeterogeneousContainer<T>& HeterogeneousContainer<T>::operator=(const HeterogeneousContainer& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
HeterogeneousContainer<T>& HeterogeneousContainer<T>::operator=(HeterogeneousContainer&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<class T>
void HeterogeneousContainer<T>:: copyFrom(const HeterogeneousContainer& other){
    size = other.size;
    capacity = other.capacity;
    objects = new T* [capacity] {};
    for(int i = 0; i < size; i++){
        objects[i] = other.objects[i]->clone(); 
    }
}

template <class T>
void HeterogeneousContainer<T>:: moveFrom(HeterogeneousContainer&& other){
    size = other.size;
    capacity = other.capacity;
    other.size = other.capacity = 0;


    objects = other.objects;
    other.objects = nullptr;

}

template <class T>
void HeterogeneousContainer<T>:: resize(size_t newCap){
    <T>** temp = new T*[newCap]{};
    for(int i = 0; i < capacity; i++){
        temp[i] = objects[i];
    }

    capacity = newCap;

    delete[] objects;
    objects = temp;

}
template <class T>
void HeterogeneousContainer<T>::free(){
    for(int i = 0; i < capacity; i++){
        delete objects[i];
    }
    delete[] objects;
}

template <class T>
void HeterogeneousContainer<T>:: addObject(const T& obj){
    if(size >= capacity){
        resize(capacity*2);
    }

    objects[size++] = obj.clone();
}

template<class T>
void HeterogeneousContainer<T>:: addObject(T* obj){
    if(size>= capacity){
        resize(capacity*2);
    }

    objects[size++]= obj;
}
template<class T>
void HeterogeneousContainer<T>:: remove(size_t idx){
    if(idx <=size){
        throw std::out_of_range("Invalid index to remove.");
    }
    delete objects[idx];

    for(int i = idx; i < size - 1; i++){
        objects[i] = objects[i+1];
    }
    objects[size - 1] = nullptr;
    size--;
}

template<class T>
void HeterogeneousContainer<T>:: swap(int i, int j){
    std:: swap(objects[i], objects[j]);
}

template<class T>
size_t HeterogeneousContainer<T>:: getSize()const{
    return size;
}