#include "ft_printf.h"

/*
** Tek bir karakteri ekrana yazdırır.
** write(1, &c, 1) -> 1=stdout (ekran), c'nin bellek adresi, 1 byte uzunluk.
** Yazdırılan karakter sayısını döndürür (ki bu her zaman 1'dir).
*/
int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

/*
** Bir karakter dizisini (string) ekrana yazdırır.
** Eğer fonksiyona gönderilen string tanımlı değilse (NULL ise), 
** standart printf fonksiyonunda olduğu gibi ekrana "(null)" yazdırır.
*/
int	ft_print_string(char *str)
{
	int	len;

	len = 0;
	// String NULL ise onu "(null)" metnine çeviriyoruz.
	if (!str)
		str = "(null)";
	
	// String'in sonunu belirten NULL (\0) karaktere gelene kadar
	// döngüyle her harfi teker teker yazdırıyoruz.
	while (str[len])
	{
		write(1, &str[len], 1);
		len++; // Her harf yazdırıldığında uzunluğu 1 artırıyoruz.
	}
	
	// Toplam yazdırılan karakter sayısını döndürüyoruz.
	return (len);
}

