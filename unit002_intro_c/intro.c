
typedef int myint;

/*struct _complex
{
    float real;
    float imag;
};

typedef struct _complex Complex;*/

typedef struct
{
    float real;
    float imag;
} Complex;

int main() {
    Complex c1, c2 = {1.4, 2.6};

    c1.real = 1.0;
    c1.imag = 2.0;
    
    myint a = 10;


    return 0;
}