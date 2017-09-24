## Homework I
Данная домашняя работа посвящена изучению шаблонов и работой с классами.

## Tasks
- [x] 1.Реализовать шаблонный класс `stack`, со следующим интерфейсом:

## Tutorial

```ShellSession
template <typename T>
class stack
{
public:
    stack();
    size_t count() const;
    void push(T const &);
    T pop();
private:
    T * array_;
    size_t array_size_;
    size_t count_;
};
```
## Result
```ShellSession
1234
1230
Now Stack is empty.
```
