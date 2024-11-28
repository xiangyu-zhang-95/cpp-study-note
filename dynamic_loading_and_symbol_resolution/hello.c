int printf(const char*, ...);

int foo(int x) {
    return x + 1;
}

int main() {
    int y = foo(12);
    printf("hello world %d\n", y);
    int z = foo(13);
    printf("another hello world %d\n", y);
}

