![image-20210909114214961](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20210909114214961.png)

![image-20210909114126556](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20210909114126556.png)

玩一玩：

$T(n)=2T(\frac{n}{2})+\Theta(n)$

此时$a=2, b=2$

$c=\log_{b}{a}=\log_22=1$

$\because \Theta(n^c)=\Theta(n)=\Theta(n)$

$\therefore T(n)=\Theta(n^{c}\log n)=\Theta(n \log n)$

---

$T(n)=T(\frac{n}{2})+\Theta(n)$

此时$a=1, b=2$

$c=\log_{b}{a}=\log_21=0$

$\because \Theta(n^c)=\Theta(n^0)<\Theta(n)$

$\therefore T(n)=\Theta(\Theta(n))=\Theta(n)$

---

$T(n)=T(\frac{n}{2})+\Theta(1)$

此时$a=1, b=2$

$c=\log_{b}{a}=\log_21=0$

$\because \Theta(n^c)=\Theta(n^0)=\Theta(1)=\Theta(1)$

$\therefore T(n)=\Theta(n^{c}\log n)=\Theta(\log n)$

---

$T(n)=2T(\frac{n}{2})+\Theta(n\sqrt{n})$

此时$a=2, b=2$

$c=\log_{b}{a}=\log_22=1$

$\because \Theta(n^c)=\Theta(n)<\Theta(n\sqrt{n})$

$\therefore T(n)=\Theta(\Theta(n\sqrt{n}))=\Theta(n\sqrt{n})$

---

### 练习题

+ $T(n)=2T(\frac{n}{4})+\sqrt{n}$​

此时$ a=2,b=4$

$c=\log_b{a}=log_4{2}=\frac{1}{2}$

$\because \Theta(n^c)=\Theta(\sqrt{n})=\Theta(\sqrt{n})$

$\therefore T(n)=\Theta(\sqrt{n}\log n)$



$T(n)=T(n-1)+n$

$\color{red}\text{喜报}$ 这题不是主定理 ——rxz

因为这题不是主定理的形式

$\therefore T(n)=T(n-1)+n\\=n+n-1+T(n-2)\\=n+n-1+n-2+T(n-3)\\=n+...+1+0\\=\frac{n(n-1)}{2}\\=\Theta(n^2)$​

