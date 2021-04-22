#ifndef OI_FASTIO
#define OI_FASTIO
#include <cstdio>
namespace OIalgo{
/*
警告：将其与其它IO并用可能导致严重的后果
原作者：[caijianhong](https://www.luogu.com.cn/user/390033)
源链接：https://www.luogu.com.cn/paste/7clcx6a0
已经过许可
*/

#define NO_IOSTREAM
namespace FAST_IO{
    static const int
        _MAX_IO_SIZE=1<<15,
        _MAX_NUMBER_LENGTH=20;
    class IO_chars{
        private: char _I_buf[_MAX_IO_SIZE],*_I_p1,*_I_p2;
        private: char _O_buf[_MAX_IO_SIZE],*_O_p1,*_O_p2;
#ifndef DEBUG
        public: inline IO_chars():_I_p1(_I_buf),_I_p2(_I_buf),_O_p1(_O_buf),_O_p2(_O_buf+_MAX_IO_SIZE){}
        public: inline ~IO_chars(){std::fwrite(_O_buf,1,_O_p1-_O_buf,stdout);}
        public: inline char getchar(){
            if(_I_p1==_I_p2){
                _I_p1=_I_buf;
                _I_p2=_I_p1+std::fread(_I_buf,1,_MAX_IO_SIZE,stdin);
            }
            return _I_p1==_I_p2?EOF:*_I_p1++;
        }
        public: inline void putchar(const char &_O_ch){
            if(_O_p1==_O_p2){
                std::fwrite(_O_buf,1,_MAX_IO_SIZE,stdout);
                _O_p1=_O_buf;
            }
            *_O_p1++=_O_ch;
        }
#else
        public: inline char getchar(){return std::getchar();}
        public: inline void putchar(const char &_O_ch){std::putchar(_O_ch);}
#endif
    } ioch;
    class IO{
        public: inline bool isdigit(const char &ch){return '0'<=ch&&ch<='9';}
        public: inline bool isblank(const char &ch){return ch<=32||ch==127;}
#define def(type) \
        public: inline IO operator>>(type &x){\
            bool f;char ch=ioch.getchar();\
            for(f=0;!isdigit(ch);f|=(ch=='-'),ch=ioch.getchar())\
                if(ch==EOF) throw "Runtime error: No any numbers to read.";\
            for(x=0; isdigit(ch);ch=ioch.getchar())\
                x=x*10+ch-'0';\
            return (f)&&(x=-x),*this;\
        }
        def(short) def(int) def(unsigned int)
        def(long long) def(unsigned long long)
#undef def
#define def(type) \
        public: inline IO operator<<(type x){\
            char stk[_MAX_NUMBER_LENGTH],cnt=0;\
            if(x<0) x=-x,ioch.putchar('-');\
            do stk[cnt++]=x%10+'0'; while(x/=10);\
            do ioch.putchar(stk[--cnt]); while(cnt);\
            return *this;\
        }
        def(short) def(int) def(unsigned int)
        def(long long) def(unsigned long long)
#undef def
        public: inline IO operator>>(char &a){
            char ch=ioch.getchar();
            for(; isblank(ch);ch=ioch.getchar())
                if(ch==EOF) return a=ch,*this;
            return a=ch,*this;
        }
        public: inline IO operator<<(const char &a){
            ioch.putchar(a);
            return *this;
        }
        public: inline IO operator>>(char *a){
            char ch=ioch.getchar();
            for(; isblank(ch);ch=ioch.getchar())
                if(ch==EOF) throw "GET EOF";
            for(;!isblank(ch);ch=ioch.getchar())
                *a++=ch;
            return *a='\0',*this;
        }
        public: inline IO operator<<(const char *a){
            for(const char *ch=a;*ch;ch++)
                ioch.putchar(*ch);
            return *this;
        }
    } io;
#ifdef DEBUG
    #undef DEBUG
#endif
#ifdef NO_IOSTREAM
    #define cin io
    #define cout io
    #define endl '\n'
#endif
};
};
#endif
