#pragma once
 
#include <iostream>
using namespace std;
#include <assert.h>
 
template <class T>
class Vector
{
public:
	/*typedef T* Iterator;*/
 
	Vector()//构造函数
		:_start(0)
		, _finish(0)
		, _endOfStorage(0)
	{}
	Vector(const T* array, size_t size)
		: _start(new T[size])
		, _finish(_start)
		, _endOfStorage(_finish)
	{
		for (size_t i = 0; i < size; ++i)
			*_finish++ = array[i];
	}
 
	Vector(const Vector<T>& v)//拷贝构造函数
	{
		_start = new T[v._finish - v._start];
		_finish = _start;
 
		for (Iterator tmp = _start; tmp != _finish; tmp++)
		{
			*(_finish) = *tmp;
			_finish++;
		}
		_endOfStorage = _finish;
	}
 
	Vector& operator=(const Vector& s)//赋值运算符重载
	{
		Iterator tmp = _start;
		tmp._start=new T[s._finish - s._start];
		if (*this != s)
		{
			for (size_t i = 0; i < size; ++i)
			{
				tmp._start[i] = _start[i];
			}
		}
		delete[] _start;
		return *tmp;
	}
 
	~Vector()//析构函数
	{
		if (_start != NULL)
		{
			_start = 0;
			_finish = 0;
			_endOfStorage = 0;
		}
	}
 
	///////////////////Modify//////////////////////
	void PushBack(const T& data)//尾插
	{
		_CheckCapacity();
		*_finish++ = data;
	}
	void PopBack()//尾删
	{
		--_finish;
	}
 
	void Insert(size_t pos, const T& data)//指定位置插入
	{
		assert(pos <= Size());
		_CheckCapacity();
		for (size_t i = Size(); i > pos; i--)
		{
			_start[i] = _start[i - 1];
		}
 
		_start[pos] = data;
		++_finish;
	}
 
	void Erase(size_t pos)//删除指定位置
	{
		assert(pos < Size());
		for (size_t i = pos; i < Size() - 1; ++i)
		{
			_start[i] = _start[i+1];
		}
		--_finish;
	}
 
 
	//////////////////capacity////////////////////
	size_t Size()const//求有效元素个数
	{
		return _finish - _start;
	}
 
	size_t Capacity()const//求总容量大小
	{
		return _endOfStorage - _start;
	}
 
	bool Empty()const//检查是否为空
	{
		return _finish - _start = 0;
	}
	void Resize(size_t newsize, const T& data = T())//重置大小
	{
		size_t oldsize = Size();
		if (newsize <= oldsize)
		{
			_finish = _start + newsize;
		}
		else if (newsize > oldsize&&newsize < Capacity())
		{
			for (size_t i = oldsize; i < newsize; i++)
			{
				_start[i] = data;
			}
			_finish = _start + newsize;
		}
		else
		{
			T* tmp = new T[newsize];
			for (size_t i = 0; i < oldsize; ++i)
			{
				tmp[i] = _start[i];
			}
 
			for (size_t i = oldsize; i < newsize; i++)
			{
				tmp[i] = data;
			}
 
			delete[] _start;
			_start = tmp;
			_finish = _start+newsize;
			_endOfStorage = _finish + newsize;
		}
	}
 
	//////////////Acess/////////////////////////// 
	T& operator[](size_t index)//重载下标运算符
	{
		return _start[index];
	}
	const T& operator[](size_t index)const
	{
		return _start[index];
	}
 
	T& Front()//返回第一个元素
	{
		return *_start;
	}
	const T& Front()const
	{
		return *_start
	}
 
	T& Back()//返回最后一个元素
	{
		return *(_finish - 1);
	}
	const T& Back()const
	{
		return *(_finish - 1);
	}
 
	void Clear()//清空
	{
		_finish = _start;
	}
 
	void diplay()
	{
		for (size_t i = 0; i < Capacity(); i++)
		{
			cout << _start[i] << "  ";
		}
		cout << "end" << endl;
	}
 
private:
	void _CheckCapacity()//检查是否有空间
	{
		size_t capacity = Capacity();
		size_t size = Size();
		if (size >= capacity)
		{
			T* tmp = new T[capacity*2+3];//开辟新空间
 
			if (_start != NULL)//拷贝元素
			{
				if (IsPOD(typeid(T).name()))//内置类型
				{
					memcpy(tmp, _start, size*sizeof(T));
				}
				else//非内置类型
				{
					for (size_t i = 0; i < size; ++i)
					{
						tmp[i] = _start[i];
					}
				}
			}
 
			if (_start)
			   delete[] _start;
 
			_start = tmp;
			_finish = _start + size;
			_endOfStorage = _finish + capacity * 2 + 3;
		}
	}
 
	template<class T>
	friend ostream& operator<<(ostream& _cout, const Vector<T>& v)
	{
		for (size_t i = 0; i < v.Size(); ++i)
			cout << v[i] << " ";
		return _cout;
	}
	bool IsPOD(const char* Typename)
	{
		static char*p[] = { "int", "double", "float", "char" };
		for (size_t i = 0; i < 4; ++i)
		{
			if ((strcmp(p[i], Typename)) == 0)
				return true;
		}
		return false;
	}
private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};
