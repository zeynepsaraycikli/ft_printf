#include "ft_printf.h"

/*
** Bu fonksiyon, '%' işaretinden sonra gelen karaktere (format belirleyiciye) 
** bakar ve uygun formata göre ilgili yazdırma fonksiyonunu çağırır.
** va_list türündeki 'args', fonksiyona yollanan sıradaki argümanı temsil eder.
*/
static int	ft_format(va_list args, const char format)
{
	int	printed_len;

	printed_len = 0;
	if (format == 'c') // Karakter yazdırma
		printed_len += ft_print_char(va_arg(args, int));
	else if (format == 's') // String (Karakter dizisi) yazdırma
		printed_len += ft_print_string(va_arg(args, char *));
	else if (format == 'p') // Pointer bellek adresi yazdırma
		printed_len += ft_print_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i') // İşaretli ondalık tam sayı (int) yazdırma
		printed_len += ft_print_number(va_arg(args, int));
	else if (format == 'u') // İşaretsiz ondalık tam sayı (unsigned int) yazdırma
		printed_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x') // Küçük harflerle hexadecimal yazdırma
		printed_len += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (format == 'X') // Büyük harflerle hexadecimal yazdırma
		printed_len += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (format == '%') // Yüzde '%' işaretinin kendisini yazdırma
		printed_len += ft_print_char('%');
	return (printed_len);
}

/*
** Ana fonksiyonumuz. Standart C kütüphanesindeki printf gibi çalışır, 
** ekrana yazdırdığı toplam karakter sayısını döndürür.
*/
int	ft_printf(const char *format, ...)
{
	int		i;
	int		total_len;
	va_list	args; // Argüman listemizi tanımlıyoruz.

	i = 0;
	total_len = 0;
	// va_start, değişken argüman listesini başlatır.
	// 'format' parametresinden sonraki argümanları yakalamak için kullanılır.
	va_start(args, format);
	
	// Format string'i sonlanana (NULL karaktere gelene) kadar karakter karakter ilerliyoruz.
	while (format[i])
	{
		// Eğer '%' işareti görürsek, kendinden sonra bir format belirleyici gelmiştir.
		if (format[i] == '%')
		{
			// '%' işaretinden bir sonraki karaktere (format[i + 1]) bakıp formatı işliyoruz.
			total_len += ft_format(args, format[i + 1]);
			i++; // Formattaki karakteri işlediğimiz için döngü sayacını bir kez daha artırıyoruz (atlıyoruz).
		}
		else
		{
			// Eğer karakter '%' değilse, sadece normal bir karakterdir, direkt yazdır.
			total_len += ft_print_char(format[i]);
		}
		i++;
	}
	// args listesi ile işlemimiz bittiğinde belleği güvenle serbest bırakmak için va_end() çağrılmalıdır.
	va_end(args);
	return (total_len); // Ekrana yazdırılan toplam karakter sayısını (uzunluğu) döndür.
}

