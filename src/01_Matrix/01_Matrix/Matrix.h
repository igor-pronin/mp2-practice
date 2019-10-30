#pragma once
#include "Vector.h"
template <class ValType>
class TMatrix : public TVector<TVector<ValType> > // сделать правильоне наследование полей // наладить throw
{
public:
	TMatrix(int size = 10);
	TMatrix(const TMatrix&);
	TMatrix(const TVector<TVector<ValType>>&);
	~TMatrix();
	bool operator ==(const TMatrix&) const;
	bool operator !=(const TMatrix&) const;
	TMatrix operator +(ValType);
	TMatrix operator -(ValType);
	TMatrix operator *(ValType);
	TVector<ValType> operator *(const TVector<ValType>&);
	TMatrix operator +(const TMatrix&);
	TMatrix operator -(const TMatrix&);
	TMatrix& operator =(const TMatrix&);
	friend ostream& operator <<(ostream& o, const TMatrix &a)
	{
		for (int i = 0; i < a.size; i++)
		{
			o << a.elements[i];
			cout << endl;
		}
		return o;
	}
	friend istream& operator >>(istream& in, TMatrix &a)
	{
		for (int i = 0; i < a.size; i++)
			{
				cout << "entering vector " << i << endl;
				in >> a.elements[i];
			}
		return in;
	}
};
template <class ValType>
TMatrix <ValType> ::TMatrix(int _size) : TVector<TVector<ValType> >(_size)
{
	if (_size < 1)
		throw "Матрица не может быть построена";
	for (int i = 0; i < _size; i++)
		this->elements[i] = TVector<ValType>(_size - i, i);
}
template <class ValType>
TMatrix <ValType> ::TMatrix(const TMatrix<ValType>& a) : TVector<TVector<ValType> >(a)
{}
template <class ValType>
TMatrix <ValType> ::TMatrix(const TVector<TVector<ValType>>& a) : TVector<TVector<ValType> >(a)
{}
template <class ValType>
TMatrix <ValType> :: ~TMatrix()
{}
template <class ValType>
bool TMatrix <ValType> ::operator ==(const TMatrix<ValType>& a) const
{
	int flag = 0;
	if (this->size != a.size)
		//cout << "Размер не совпалает!" << endl;
		return false;
	for (int i = 0; i < a.size; i++)
	{
		if (this->elements[i] != a.elements[i])
			flag = 1;
	}
	if (flag == 0)
		return true;
	return false;
}
template <class ValType>
bool TMatrix<ValType> :: operator !=(const TMatrix<ValType>& a) const
{
	if ((*this == a) == true)
		return false;
	return true;
	//return !(*this == a);
}
template <class ValType>
TMatrix <ValType> TMatrix <ValType> :: operator +(ValType a)
{
	TMatrix b(this->size);
		for (int i = 0; i < this->size; i++)
			b.elements[i] = this->elements[i] + a;
	return b;
}
template <class ValType>
TMatrix <ValType> TMatrix <ValType> :: operator -(ValType a)
{
	TMatrix b(this->size);
	for (int i = 0; i < this->size; i++)
		b.elements[i] = this->elements[i] - a;
	return b;
}
template <class ValType>
TMatrix <ValType> TMatrix <ValType> :: operator *(ValType a)
{
	TMatrix b(this->size);
	for (int i = 0; i < this->size; i++)
		b.elements[i] = this->elements[i] * a;
	return b;
}
template <class ValType>
TVector <ValType> TMatrix <ValType> :: operator *(const TVector <ValType> &a)
{
	if (this->size != a.size)
		throw "Размеры матрицы и вектора не совпадают";
	TVector<ValType> b(a.size, 0);
	for (int i = 0; i < this->size; i++)
	for (int j = this->elements[i].startIndex; j < this->elements[i].size; j++)
		b.elements[i] += this->elements[i][j] * a.elements[j];
	return b;
}
template <class ValType>
TMatrix <ValType> TMatrix <ValType> :: operator + (const TMatrix<ValType> &a)
{
	if (this->size != a.size)
		throw "Размер не совпадает";
	TMatrix b(a.size);
	for (int i = 0; i < this->size; i++)
		b.elements[i] = this->elements[i] + a.elements[i];
	return b;
}
template <class ValType>
TMatrix <ValType> TMatrix <ValType> :: operator - (const TMatrix<ValType> &a)
{
	if (this->size != a.size)
		throw "Размер не совпадает";
	TMatrix b(a.size);
	for (int i = 0; i < this->size; i++)
			b.elements[i] = this->elements[i] - a.elements[i];
	return b;
}
template <class ValType>
TMatrix <ValType>& TMatrix <ValType> ::operator = (const TMatrix<ValType> &a)
{
	if (*this == a)
		return *this;
	if (this->size != a.size)
	{
		delete[] this->elements;
		this->size = a.size;
		this->elements = new TVector<ValType>[this->size];
	}
	//memcpy(this->elements, a.elements, this->size * sizeof(ValType));
	for (int i = 0; i < this->size; i++)
		this->elements[i] = a.elements[i];
	return *this;
}


