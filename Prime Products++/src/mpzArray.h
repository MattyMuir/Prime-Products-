#pragma once
#include <vector>
#include <stdio.h>
#include <iostream>
#include <memory>

#include <mpir.h>

class mpzxx
{
public:
	~mpzxx()
	{
		mpz_clear(data);
	}
	mpz_t data;
};

class mpzArray
{
public:
	// Functions
	mpzArray();
	mpzArray(int count);
	~mpzArray();

	void Clear();
	void TempClear();
	mpz_t& operator[](int i);
	int Size();
	void Back();
	void Back(mpz_t element);
	void BackUI(uint64_t element);
	void DeepCopy(mpzArray& other);

private:
	std::vector<std::shared_ptr<mpzxx>> mData;
	int size;
};