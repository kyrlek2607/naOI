#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)
#define all(v) begin(v), end(v)
#define st first
#define nd second
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
using ll = long long;
using bigi = __int128;
using ull = unsigned long long;
using namespace std;
pair<ll, ll> euk(ll a, ll b){
    if(a == 0) return {0, 1};
    auto [x, y] = euk(b % a, a);
    return {y - (b / a) * x, x};
}
// ax + by = g
// g = gcd(a, b)
// xall = x + k * b / g
// yall = y - k * a / g
struct Cin {
    static const int Size = 1 << 21;
    char ibuf[Size];
    int i = 0, e = 0;
    
    int GetChar() {
        if (i == e) {
            e = fread(ibuf, 1, Size, stdin);
            i = 0;
            if(!e) return EOF;
        }
        return ibuf[i++];
    }
    
    inline int GetWhite() {
        int c = GetChar();
        while (c <= ' ' && c != EOF) c = GetChar();
        return c;
    }
    
    Cin& operator>>(char& c) {
        c = GetWhite();
        return *this;
    }
    Cin& operator>>(string& s) {
        s.clear();
        int c = GetWhite();
        while (c > ' ' && c != EOF) {
            s.push_back(c);
            c = GetChar();
        }
        return *this;
    }
    template <typename T>
    Cin& operator>>(T& a) {
        if constexpr (is_floating_point_v<T>){
            static string s;
            s.clear();
            int c = GetWhite();
            if(c == '+') c = GetChar();
            while (c != EOF && c > ' ') {
                s.push_back(c);
                c = GetChar();
            }
            from_chars(s.c_str(), s.c_str() + s.size(), a);
        }
        else{
            int c = GetWhite();
            bool im = c == '-';
            if (c < '0' || c > '9') c = GetChar();
            a = 0;
            while (c >= '0' && c <= '9') {
                a = 10 * a + (1 - 2 * im) * (c - '0');
                c = GetChar();
            }
        }
        return *this;
    }
    
    Cin& operator>>(bool& b){
        int x;
        operator>>(x);
        b = x;
        return *this;
    }
    
    
};
struct Cout{
    ~Cout() { Flush(); }
    static const int Size = 1 << 21;
    static const int Fsize = 1 << 17;
    char obuf[Size];
    char fbuf[Fsize];
    int o = 0;
    int prec = 6;
    void Flush() {
        fwrite(obuf, 1, o, stdout);
        o = 0;
    }
    inline bool ToFlush(int ile = 64) const {
        return ile >= Size - o;
    }
    void PutChar(char c) {
        if (ToFlush()) Flush();
        obuf[o++] = c;
    }
    Cout& operator<<(const string& s) {
        for (auto c : s) PutChar(c);
        return *this;
    }
    Cout& operator<<(const char* s) {
        while(*s) PutChar(*s++);
        return *this;
    }
    Cout& operator<<(char* s) {
        return operator<<((const char*)s);
    }
    Cout& operator<<(char c) {
        PutChar(c);
        return *this;
    }
    Cout& operator<<(__int128 x) {
        if (x < 0) {
            PutChar('-');
            return operator<<(-(unsigned __int128)x);
        }
        return operator<<((unsigned __int128)x);
    }
    Cout& operator<<(unsigned __int128 x) {
        if (x <= ULLONG_MAX) return operator<<((unsigned long long)x);
        char buf[64];
        int n = 0;
        while (x) { buf[n++] = '0' + (int)(x % 10); x /= 10; }
        while (n) PutChar(buf[--n]);
        return *this;
    }
    template <typename T>
    Cout& operator<<(const T& a) {
        if(ToFlush()) Flush();
        o = to_chars(obuf + o, obuf + Size, a).ptr - obuf;
        return *this;
    }
    Cout& operator<<(const bool& b){
        int x = b;
        return operator<<(x);
    }
    Cout& operator<<(const float& f){
        return operator<<((long double)f);
    }
    Cout& operator<<(const double& f){
        return operator<<((long double)f);
    }
    Cout& operator<<(const long double& f){
        const int n = snprintf(fbuf, Fsize, "%.*Lf", prec, f);
        if(ToFlush(n)) Flush();
        memcpy(obuf + o, fbuf, n);
        o += n;
        return *this;
    }
};
Cin ci;
Cout co;
int main(){
    int a;
    ci >> a;
    co << a << '\n';
}
