#include "ft_printf.h"

/*
** İşaretli (signed) tam sayıları (base 10) yazdırır.
*/
int	ft_print_number(int n)
{
	int		len;
	long	num;

	len = 0;
	// Minimum tam sayıyı (INT_MIN) pozitif yaparken taşma (overflow) yaşanmaması 
	// için sayıyı 'long' değişkenine aktarıyoruz.
	num = n;
	
	// Eğer sayı negatifse, önce eksi '-' karakterini yazdırıp sayıyı pozitife çeviriyoruz.
	if (num < 0)
	{
		len += ft_print_char('-');
		num = -num;
	}
	
	// Eğer sayı 9'dan büyükse, sayıyı 10'a bölerek en sağdaki basamak hariç 
	// geri kalan kısmı yazdırmak üzere fonksiyonu kendi içinde (recursive) çağırıyoruz.
	if (num > 9)
		len += ft_print_number(num / 10);
	
	// Sayının 10'a bölümünden kalanı bulup (en sağdaki basamak), 
	// '0' karakterinin ASCII değerini ekleyerek char (harf) formatına çeviriyor ve yazdırıyoruz.
	len += ft_print_char((num % 10) + '0');
	
	// Sayının yazdırılmasından elde edilen toplam uzunluğu döndürüyoruz.
	return (len);
}

/*
** İşaretsiz (unsigned) tam sayıları (base 10) yazdırır.
** Unsigned sayılar hiçbir zaman eksi (-) olamazlar.
*/
int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	
	// Sayı 9'dan büyükse, kendi kendini (recursive) çağır.
	if (n > 9)
		len += ft_print_unsigned(n / 10);
		
	// Mod 10 ile son rakamı al ve char karakteri olarak ekrana bas.
	len += ft_print_char((n % 10) + '0');
	
	return (len);
}

