error because of `__attribute__((packed))`  
If you remove it then error will disappear...
```
error: cannot bind packed field ‘obj.my_struct::a’ to ‘quint32&’ {aka ‘unsigned int&’}
```