#pragma once
template <class T>
class TStack
{
	T* Mas;
	int Size; 
	int MaxSize;
public:
	TStack(int _MaxSize = 100)
	{
		if (MaxSize <= 0)
			throw _MaxSize;
		MaxSize =_MaxSize;
		Size = 0;
		Mas = new T [MaxSize];
	}
	~TStack()
	{
		delete [] Mas;
	}
	TStack (const TStack &ts)
	{
		MaxSize = ts.MaxSize;
		Size = ts.Size;
		Mas = new T [MaxSize];
		for (int i = 0; i < Size; i++)
		{
			Mas[i] = ts.Mas[i];
		}
	}
	TStack &operator=(const TStack &ts)
	{
		MaxSize = ts.Max.Size;
		Size = ts.Size;
		Mas = new T [MaxSize];
		for (int i = 0; i<Size; i++)
		{
			Mas[i] = ts.Mas[i];
		}
		return *this;
	}
	int IsEmpty()
	{
		if (Size==0) return 1;
		return 0;
	}
	int IsFull()
	{
		if (Size==MaxSize) return 1;
		return 0;
	}
	void Push (const T & El)
	{
		if (IsFull()) throw MaxSize;
		Mas[Size]=El;
		Size++;
	}
	T Top() const 
	{
		if (IsEmpty()) throw -1;
		return Mas[Size-1];
	}
	T Pop()
	{
		if (IsEmpty()) throw -1;
		Size--;
		return Mas[Size];
	}

};
