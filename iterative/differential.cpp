#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using BYTE = unsigned char;
using INT = unsigned int;


INT S[8][64]=
{
  {14, 4, 13, 1, 2, 15, 11, 8, 3 , 10, 6, 12, 5, 9, 0, 7,
  0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
  4, 1 , 14, 8, 13, 6, 2, 11, 15, 12, 9, 7,3, 10, 5, 0,
  15, 12, 8,2,4, 9, 1,7 , 5, 11, 3, 14, 10, 0, 6, 13},
  
  {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0,5, 10,
  3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
  0, 14, 7, 11, 10, 4, 13, 1, 5, 8,12, 6, 9, 3, 2, 15,
  13, 8, 10, 1, 3, 15, 4, 2,11,6, 7, 12, 0,5, 14, 9},
  
  {10, 0, 9,14,6,3,15,5, 1, 13, 12, 7, 11, 4,2,8,
  13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
  13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12,5, 10, 14, 7,
  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},
  
  {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
  13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
  10, 6, 9, 0, 12, 11, 7, 13, 15, 1 , 3, 14, 5, 2, 8, 4, 
  3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},
  
  
  {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 
  14, 11,2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 
  4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 
  11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}, 
  
  
  
  {12, 1, 10, 15, 9, 2, 6,8, 0, 13, 3, 4, 14, 7, 5, 11, 
  10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 
  9, 14, 15, 5, 2,8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 
  4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}, 
  
  {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
  13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
  1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 
  6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},
  
  {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12,7, 
  1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 
  7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 
  2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};

INT S_MAP[64] = {
    1, 17, 2, 18, 3, 19, 4, 20, 5, 21, 6, 22, 7, 23, 8, 24,
    9, 25, 10, 26, 11, 27, 12, 28, 13, 29, 14, 30, 15, 31, 16, 32,
    33, 49, 34, 50, 35, 51, 36, 52, 37, 53, 38, 54, 39, 55, 40, 56,
    41, 57, 42, 58, 43, 59, 44, 60, 45, 61, 46, 62, 47, 63, 48, 64
};


/* INITIAL PERMUTATION (IP) */

INT IP_[] = {
  58,50,42, 34,26,18,10,2,
  60,52,44,36,28,20,12,4,
  62,54, 46, 38, 30, 22, 14,6,
  64, 56, 48, 40,32,24, 16, 8,
  57, 49, 41, 33,25,17, 9,1,
  59, 51,43,35,27,19,11,3,
  61,53,45,37,29,21,13, 5,
  63,55, 47,39,31,23,15,7
};

/* REVERSE PERMUTATION (RFP) */

INT RFP_[] = {
  8,40,16,48,24,56,32,64,
  7, 39,15,47,23,55,31,63,
  6,38,14,46,22,54,30,62,
  5,37,13,45, 21,53,29,61,
  4,36,12,44,20,52,28,60,
  3, 35, 11,43,19,51,27,59,
  2, 34, 10, 42,18, 50,26,58,
  1,33,9,41, 17, 49, 25,57
};

/* E BIT_SELECTION TABLE */

INT E_[] = {
  32, 1, 2, 3, 4, 5,
  4, 5,6, 7, 8, 9,
  8, 9, 10, 11, 12, 13,
  12, 13, 14, 15, 16, 17, 
  16, 17, 18, 19, 20, 21, 
  20, 21, 22, 23, 24, 25, 
  24, 25, 26, 27, 28, 29,
  28, 29, 30, 31, 32, 1
};


/* PERMUTATION FUNCTION P */
INT P_[] = {
  16, 7, 20, 21, 
  29, 12, 28, 17,
  1, 15, 23, 26,
  5, 18, 31,10,
  2, 8, 24, 14,
  32, 27, 3, 9,
  19, 13, 30, 6,
  22, 11, 4, 25
};


/* Inverse of P */
INT INV_P_[] = {
	9, 17, 23, 31,
	13, 28, 2, 18,
	24, 16, 30, 6,
	26, 20, 10, 1,
	8, 14, 25, 3,
	4, 29, 11, 19,
	32, 12, 22, 7,
	5, 27, 15, 21
};

/*TYPE CONVERSIONS*/

// converts hexadecimal to binary
void hex2bin(string hex, int bin[64]){
    int dig;
    for(int i = 0; i < hex.length(); i++){
        dig = 0;
        if(hex[i] <= '9' && hex[i] >= '0')
            dig = hex[i] - '0';
        else if(hex[i] <= 'F' && hex[i] >= 'A')
            dig = hex[i] - 'A' + 10;
        
        bin[4*i+3] = dig%2;
        bin[4*i+2] = (dig/2)%2;
        bin[4*i+1] = (dig/4)%2;
        bin[4*i+0] = (dig/8)%2;
    }
}

// converts binary to hexadecimal
void bin2hex(int bin[64], string &hex){
    hex.resize(16);
    int dig = 0;
    for(int i = 0; i < 16; i++){
        dig = 8*bin[4*i] + 4*bin[4*i+1] + 2*bin[4*i+2] + 1*bin[4*i+3];
        if(dig <= 9 && dig >= 0)
            hex[i] = '0' + dig;
        else if(dig <= 15 && dig >= 10)
            hex[i] = 'A' + dig -10;
    }
}

// converts standard hexadecimal to the one used in assignment
string toSpHex(const string hex){
    string spHex(16, '-');
    for(int i = 0; i < hex.length(); i++){
        if(hex[i] <= '9' && hex[i] >= '0')
            spHex[i] = hex[i] - '0' + 'f';
        else if(hex[i] <= 'F' && hex[i] >= 'A')
            spHex[i] = hex[i] - 'A' + 'f' + 10;
    }
    return spHex;
}

// converts assingment hexadecimal to standard hexadecimal
string fromSpHex(const string SpHex){
    string hex(16, '-');
    char temp;
    for(int i = 0; i < SpHex.length(); i++){
        temp = SpHex[i] - 'f';
        if(temp <= 9 && temp >= 0)
            hex[i] = temp + '0';
        else if(temp <= 15 && temp >= 10)
            hex[i] = temp + 'A' - 10;
    }
    return hex;
}

// converts decimal to binary
void dec2bin(long long int x, int bin[], int size){
    for(int i = 0; i < size; i++){
        bin[i] = 0;
    }
    for(int i = 0; i < size && x >= 0; i++){
        bin[size - i - 1] = x%2;
        x /= 2;
    }
}

// converts binary to decimal
long long int bin2dec(int bin[], int size){
    long long int x = 0, pow2 = 1;
    for(int i = 0; i < size; i++){
        x += bin[size - i - 1] * pow2;
        pow2 *= 2;
    }
    return x;
}

/*PERMUTATION OPERATIONS*/

// initial permutation
void IP(int bin[64]){
    int temp[64];
    for(int i = 0; i < 64; i++){
        temp[i] = bin[i];
    }
    for(int i = 0; i < 64; i++){
        bin[i] = temp[IP_[i]-1];
    }
}

// inverse of initial permutation
void invIP(int bin[64]){
    int temp[64];
    for(int i = 0; i < 64; i++){
        temp[i] = bin[i];
    }
    for(int i = 0; i < 64; i++){
        bin[IP_[i]-1] = temp[i];
    }
}

// final permutation
void FP(int bin[64]){
    int temp[64];
    for(int i = 0; i < 64; i++){
        temp[i] = bin[i];
    }
    for(int i = 0; i < 64; i++){
        bin[i] = temp[RFP_[i]-1];
    }
}

// inverse of final permutation
void invFP(int bin[64]){
    int temp[64];
    for(int i = 0; i < 64; i++){
        temp[i] = bin[i];
    }
    for(int i = 0; i < 64; i++){
        bin[RFP_[i]-1] = temp[i];
    }
}

// gets left and right half of text
void getLR(int bin[64], int L[32], int R[32]){
    for(int i = 0; i < 64; i++){
        if(i >= 32)
            R[i-32] = bin[i];
        else
            L[i] = bin[i];
    }
}

// expansion
void E(int inp[32], int inpE[48]){
    for(int i = 0; i < 48; i ++){
        inpE[i] = inp[E_[i] - 1];
    }
}

// permutation
void P(int bin[32]){
    int temp[64];
    for(int i = 0; i < 32; i++){
        temp[i] = bin[i];
    }
    for(int i = 0; i < 32; i++){
        bin[i] = temp[P_[i]-1];
    }
}

// inverse of permutation
void invP(int bin[32]){
    int temp[64];
    for(int i = 0; i < 32; i++){
        temp[i] = bin[i];
    }
    for(int i = 0; i < 32; i++){
        bin[i] = temp[INV_P_[i]-1];
    }
}

/*UTILITY OPERATIONS*/

// Saves A xor B in result (all in binary)
void XOR(const int A[], const int B[], int result[], int size){
    for(int i = 0; i < size; i++){
        result[i] = (A[i]+B[i])%2;
    }
}

// prints binary form
void print(const int bin[], int size){
    for(int i = 0; i < size; i++){
        cout << bin[i];
    }
    cout << endl;
}

// separate parts of input based on which S-box they go to
void separate(int inp[], int sep[], int size_i, int size_s){
    int size = size_i/size_s, sum = 0, pow2 = 1;
    for(int i = 0; i < size_s; i++){
        sum = 0;    pow2 = 1;
        for(int j = 0; j < size; j++){
            sum += inp[size*(i+1) - j - 1]*pow2;
            pow2 *= 2;
        }
        sep[i] = sum;
    }
} 
int main(){
    // string num ="\0";
    // cout << "Enter ID of characteristic to be used (1/2): ";
    // cin >> num;
    // if((num.compare("1") != 0) && (num.compare("2") != 0)){
    //     cout << "Please enter valid ID from 1 and 2." << endl;
    //     return 0;
    // }

    string T1, T2;
    ifstream out("outputs.txt");
    ofstream text_keys("keys_distribution.txt"), key_6i("key_6i.txt");

    string characteristic = "405C000004000000";

    int chr[64], cl[32], cr[32];
    hex2bin(characteristic, chr);
    getLR(chr, cl, cr);

    // counter for each S box and each key
    long long int KEY_COUNT[8][64];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 64; j++){
            KEY_COUNT[i][j] = 0;
        }
    }

    int count = 0;

    int iter = 0;
    while(getline(out, T1)){
        
        getline(out, T2);
        // get ciphertexts for both inputs
        
        int t1[64], t2[64], oXOR[64], lXOR[32], rXOR[32], l1[32], r1[32], l2[32], r2[32], El1[48], El2[48], Exor[48];
        
        T1 = fromSpHex(T1); T2 = fromSpHex(T2);
        hex2bin(T1, t1);      hex2bin(T2, t2);
        
        // inverse final permutation
        invFP(t1);  invFP(t2);
        
        // get left and right halves of the ciphertexts
        getLR(t1, l1, r1);  getLR(t2, l2, r2);
        
        // get XOR value of cihpertexts, along with left and right halves
        XOR(t1, t2, oXOR, 64);
        getLR(oXOR, lXOR, rXOR);

        // print(t1, 64);
        // print(t2, 64);
        // print(oXOR, 64);
        // print(lXOR, 32);
        // print(rXOR, 32);

        // apply expansion to left half of output (right half of input to 5th round)
        E(l1, El1);  E(l2, El2);
        XOR(El1, El2, Exor, 48);
        // print(l1, 32);
        // print(El1, 48);

        int alpha[2][8], betaXOR[8], gammaXOR[8];
        separate(El1, &alpha[0][0], 48, 8);
        separate(El2, &alpha[1][0], 48, 8);
        separate(Exor, betaXOR,     48, 8);

        int Sout[32];
        XOR(rXOR, cr, Sout, 32);
        invP(Sout);
        separate(Sout, gammaXOR,    32, 8);
        // for(int i = 0; i < 2; i++){
        //     for(int j = 0; j < 8; j++){
        //         cout << alpha[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // for(int j = 0; j < 8; j++){
        //     cout << betaXOR[j] << " ";
        // }
        // cout << endl;

        for(int i = 0; i < 8; i++){
            int beta[2], S_b1, S_b2, key;
            for(int b = 0; b < 64; b++){
                beta[0] = b;
                beta[1] = betaXOR[i]^beta[0];
                S_b1 = S[i][S_MAP[beta[0]] - 1];
                S_b2 = S[i][S_MAP[beta[1]] - 1];

                if(S_b1^S_b2 == gammaXOR[i]){
                    key = alpha[0][i]^beta[0];
                    KEY_COUNT[i][key]++;
                }
            }
        }
    
        iter++;
    }

    // output distribution of keys for further processing
    for(int i = 0; i < 8; i++){
        text_keys << "S" << i+1 << "\t";
        for(int j = 0; j < 64; j++){
            text_keys << setw(3) << KEY_COUNT[i][j] << "  ";
        }
        text_keys << "\n";
    }

    // get max key
    for(int i = 0; i < 8; i++){
        int mx = INT32_MIN, ind = -1, key_i[6];
        double sum = 0;
        for(int j = 0; j < 64; j++){
            sum += KEY_COUNT[i][j];
            if(KEY_COUNT[i][j] > mx){
                mx = KEY_COUNT[i][j];
                ind = j + 1;
            }
        }
        dec2bin(ind, key_i, 6);
        cout << "S" << i+1 << "\tkey_max = ";
        print(key_i, 6);
        cout << "freq = " << mx << "\tavg = " << sum/64.0 << endl << endl;

        // key_6i << ind;
        for(int k = 0; k < 6; k++){
            key_6i << key_i[k];
        }
        key_6i << endl;
    }
}