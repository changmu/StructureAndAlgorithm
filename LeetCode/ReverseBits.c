uint32_t reverseBits(uint32_t n) {
    uint32_t left = 0x1 << 31, right = 0x1;

    while (left > right) {
        if (((n & left) | (n & right)) && !((n & left) && (n & right))) {
            if (n & left) n &= ~left;
            else n |= left;
            if (n & right) n &= ~right;
            else n |= right;
        }
        left >>= 1;
        right <<= 1;
    }
    
    return n;
}
