unsigned long long tmp;

unsigned long long duplicatebits(unsigned long long n)
{
    tmp = (n ^ (n >> 16)) & 0x00000000ffff0000;
    n ^= (tmp ^ (tmp << 16));
    tmp = (n ^ (n >> 8))  & 0x0000ff000000ff00;
    n ^= (tmp ^ (tmp << 8));
    tmp = (n ^ (n >> 4))  & 0x00f000f000f000f0;
    n ^= (tmp ^ (tmp << 4));
    tmp = (n ^ (n >> 2))  & 0x0c0c0c0c0c0c0c0c;
    n ^= (tmp ^ (tmp << 2));
    tmp = (n ^ (n >> 1))  & 0x2222222222222222;
    n ^= (tmp ^ (tmp << 1));
    return n | (n << 1);
}
