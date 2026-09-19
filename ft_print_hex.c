#include "ft_printf.h"

/*
** Bir sayıyı 16'lık (hexadecimal) tabanda yazdırır.
** Eğer 'is_upper' parametresi 1 ise harfler (A-F) büyük yazılır,
** eğer 'is_upper' 0 ise harfler (a-f) küçük yazılır.
*/
int	ft_print_hex(unsigned int num, int is_upper)
{
	int		len;
	char	*base;

	len = 0;
	
	// is_upper durumuna göre hangi karakter dizisini referans alacağımızı seçiyoruz.
	if (is_upper)
		base = "0123456789ABCDEF"; // %X formatı için
	else
		base = "0123456789abcdef"; // %x formatı için

	// Sayı 16 veya daha büyükse, 16'ya bölerek özyineli (recursive) olarak 
	// kalan basamakları yazdırması için kendi kendini çağırırız.
	if (num >= 16)
		len += ft_print_hex(num / 16, is_upper);
		
	// 16'ya bölümünden kalan sayıyı (num % 16) base string'indeki 
	// ilgili karaktere dönüştürüp ekrana basarız.
	len += ft_print_char(base[num % 16]);
	
	return (len);
}

/*
** Pointer adreslerini hexadecimal değere çevirmek için oluşturduğumuz
** yardımcı recursive fonksiyon.
** Pointer verileri uzun sayılar (unsigned long long) oldukları için 
** 16'ya bölme işlemini bu veri tipiyle yönetiyoruz.
*/
static int	ft_print_ptr_hex(unsigned long long num)
{
	int		len;
	char	*base;

	len = 0;
	// Pointer formatları genelde küçük harflerle (a-f) ifade edilir.
	base = "0123456789abcdef";
	
	if (num >= 16)
		len += ft_print_ptr_hex(num / 16);
		
	len += ft_print_char(base[num % 16]);
	return (len);
}

/*
** Void pointer (%p) değerlerini yazdırmak için ana fonksiyon.
** Bir pointer bellekteki adresi ifade eder ve C standartlarında "%p" ile
** ekrana basılırken başına "0x" takısı alır.
*/
int	ft_print_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	
	// Öncelikle ekrana hex öneki olan "0x" değerini yazdır.
	len += ft_print_string("0x");
	
	// Ardından pointer değişkeninin bellek adresini hexadecimal'e çevir ve yazdır.
	len += ft_print_ptr_hex(ptr);
	
	return (len); // Toplam yazdırılan uzunluğu döndür.
}

