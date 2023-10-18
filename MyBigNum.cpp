#include "MyBigNum.h"

void MyBigNum::setHex(string str)
{
	int r = 0,len=0;
	for (int i = 0; i <= SIZE; i++) {
		_numD[i] = 0;
	}
	Lenght = str.size();
	for (int i = Lenght-1; i >= 0; --i) {
		if (str[i] >= '0' && str[i] <= '9')
			r = str[i] - 48;
		else if (str[i] >= 'a' && str[i] <= 'f')
			r = str[i] - 87;
		else if (str[i] >= 'A' && str[i] <= 'F')
			r = str[i] - 55;
		_numD[len]=  r ;
		len++;
	
	}
}

string MyBigNum::getHex()
{
    string HEX="";
    int i = Lenght - 1;
    for (i = Lenght - 1; i >= 0 && this->_numD[i]==0 ; --i);
    while (i >= 0) {
        if (_numD[i] == 10)
            HEX+= 'a';
        else if (_numD[i] == 11)
            HEX+= 'b';
        else if (_numD[i] == 12)
            HEX+= 'c';
        else if (_numD[i] == 13)
            HEX+= 'd';
        else if (_numD[i] == 14)
            HEX+= 'e';
        else if (_numD[i] == 15)
            HEX+= 'f';
        else
            HEX+= to_string(_numD[i]);
        --i;
    }
    return HEX;

}

void MyBigNum::ADD(MyBigNum *rez, MyBigNum* second)
{
    int left = 0;
    for (int i = 0; i < SIZE; ++i) {
        rez->_numD[i] = this->_numD[i] + second->_numD[i] + left;
        left = rez->_numD[i] / 16;
        rez->_numD[i] %= 16;
    }
    return ;
}

void MyBigNum::SUB(MyBigNum* rez, MyBigNum* second)
{
    
    int taken = 0;
    if (compare(second)) {
        for (int i = 0; i < SIZE; ++i) {
            
                rez->_numD[i] = this->_numD[i] - second->_numD[i] - taken;
                if (rez->_numD[i] < 0) {
                    rez->_numD[i] += 16;
                    taken = 1;
                }
                else taken = 0;
            
            
        }
    }
    else {
        for (int i = 0; i < SIZE; ++i) {
            rez->_numD[i] = second->_numD[i] - this->_numD[i] - taken;
            if (rez->_numD[i] < 0) {
                taken = 1, rez->_numD[i] += 16;
            }
            else {
                taken = 0;
            }
        }
    }

}

void MyBigNum::MOD(MyBigNum* rez, MyBigNum* second) 
{
    int sub[SIZE];
    //int i = 0, j, carry;
    //memset(div, 0, sizeof(int) * MAX);
    //memset(rst, 0, sizeof(int) * MAX);
    //while (!big_sub(rst, a, b)) { //keep doing rst = a-b , a = rst , div + 1
    //    big_assign(a, rst);
    //    div[0]++;
    //    for (i = 0; i < MAX; i++) { // carry 
    //        if (div[i] == 16) {
    //            div[i] = 0;
    //            div[i + 1] += 1;
    //        }
    //    }
    //}
}

bool MyBigNum::compare(MyBigNum* second)
{
    int i = SIZE - 1;
    while (i > 0 && this->_numD[i] == second->_numD[i]) --i;
    return this->_numD[i] - second->_numD[i];
}
