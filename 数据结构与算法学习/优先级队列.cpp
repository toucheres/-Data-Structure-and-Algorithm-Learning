#include"优先级队列.h"



void myvipqeu::push(T tpnum)
{
	if (size == cap)
	{
		std::cout << "容量已满" << std::endl;
		return;
	}
	int tpindex = this->size + 1;

	while (tpnum > this->arr[tpindex / 2])
	{
		this->arr[tpindex] = this->arr[tpindex / 2];
		tpindex /= 2;
	}
	arr[tpindex] = tpnum;
	this->size++;
}

void myvipqeu::pop()
{
	if (this->size == 0)
	{
		std::cout << "队列为空" << std::endl;
	}

	int index = 1;
	int tar = this->arr[size];
	(this->size)--;
	while (1)
	{
		int c = 0;
		int lc = this->getLeftChildIndex(index);
		int rc = this->getRightChildIndex(index);
		if (lc == -1&&rc==-1)
		{
			break;
		}
		if (lc != -1 && rc == -1)
		{
			c = lc;
		}
		if (rc != -1 && lc == -1)
		{
			c = rc;
		}
		if (lc != -1 && rc != -1)
		{
			c = this->arr[lc] < this->arr[rc] ? rc : lc;
		}
		if (tar < this->arr[c])
		{
			arr[index] = arr[c];
			index = c;
			continue;
		}
		else
		{
			break;
		}
	}

	this->arr[index] = tar;
}

void myvipqeu::print()
{
	int hight = this->getHight();
	long wight = pow(2, hight) - 1;

	int normalgap = 7;
	int startgap = normalgap / 2;
	int higthgap = normalgap / 2;
	int index = pow(2, hight - 1);

	for (int line = 1; line <= hight; line++)
	{

		//if (line == 0) 
		//{	
		//	for (int tp4 = 0; tp4 < normalgap/2; tp4++)
		//	{
		//		std::cout << " ";
		//	}
		//	for (int tp2 = index; tp2 <= this->size; tp2++)
		//	{
		//		std::cout << this->arr[tp2];
		//		for (int tp6 = 0; tp6 < normalgap; tp6++)
		//		{
		//			std::cout << " ";
		//		}
		//	}
		//	for (int tp5 = 0; tp5 < normalgap/2; tp5++)
		//	{
		//		std::cout << std::endl;
		//	}
		//	std::cout << std::endl;
		//	startgap = normalgap;
		//	higthgap = normalgap;
		//	normalgap = normalgap * 2 + 1;		
		//	
		//	index /= 2;
		//	continue;
		//}

		//else
		//{
		for (int tp1 = 0; tp1 < startgap; tp1++)
		{
			std::cout << " ";
		}
		for (int tp3 = index; tp3 != index * 2 && tp3 != this->size + 1; tp3++)
		{
			std::cout << arr[tp3];
			for (int tp4 = 0; tp4 < normalgap; tp4++)
			{
				std::cout << " ";
			}

		}
		std::cout << std::endl;
		for (int tp5 = 0; tp5 < higthgap; tp5++)
		{
			std::cout << std::endl;
		}


		startgap = normalgap;
		higthgap = normalgap;
		normalgap = normalgap * 2 + 1;

		index /= 2;

		//}



	}
}

T myvipqeu::operator[](int index)
{
	return this->arr[index + 1];
}

int myvipqeu::getHight()
{
	int tpsize = this->size;
	int hight = 0;
	while (tpsize)
	{
		tpsize /= 2;
		hight++;
	}

	return hight;
}

int myvipqeu::getLeftChildIndex(int par)
{
	int tl = 2 * par;
	if (this->size < tl)
	{
		return -1;
	}
	return tl;
}

int myvipqeu::getRightChildIndex(int par)
{
	int tl = 2 * par + 1;
	if (this->size < tl)
	{
		return -1;
	}
	return tl;
}

myvipqeu::myvipqeu(int tsize)
{
	this->cap = tsize;
	this->size = 0;
	this->arr = (T*)malloc(sizeof(T) * (this->cap + 1));
	arr[0] = INT_MAX;
}

myvipqeu::~myvipqeu()
{
	free(this->arr);
	arr = NULL;
}



int main()
{
	myvipqeu* vipq = new myvipqeu(20);
	vipq->push(3);
	vipq->push(5);
	vipq->push(9);
	vipq->push(7);
	vipq->push(1);
	vipq->push(3);
	vipq->push(12);
	vipq->push(6);
	vipq->push(8);
	vipq->push(4);

	vipq->push(3);
	vipq->push(2);
	vipq->push(1);
	vipq->push(4);
	vipq->push(1);

	vipq->print();
	vipq->pop();
	vipq->print();
	return 0;
}