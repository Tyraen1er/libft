int main()
{
	char	str[] = "hello";
	char	*str2;

	str2 = malloc(20);
	printf("%p\n", &str);
	printf("%p\n", &str2);
	printf("%p\n", &"abc");
	return 0;
}
