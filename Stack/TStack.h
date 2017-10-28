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

};
