#include <string.h>

class ToyString
{
public:
    ToyString &operator=(const ToyString &s)
    {
        if(&s==this)return *this;
        this->m_len = s.m_len;
        free(m_data);
        m_data=(char*)malloc(sizeof(char)*s.m_len);
        memcpy(this->m_data, s.m_data, s.m_len);
        return *this;
    }

private:
    int m_len;
    char *m_data;
};