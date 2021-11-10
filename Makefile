.DEFAULT_GOAL := all
norminette:
	-norminette ./ex00/ft_foreach.c
	-norminette ./ex01/ft_map.c
	-norminette ./ex02/ft_any.c
	-norminette ./ex03/ft_count_if.c
	-norminette ./ex04/ft_is_sort.c
	-norminette ./ex06/ft_sort_string_tab.c
	-norminette ./ex07/ft_advanced_sort_string_tab.c

compile: norminette
	-gcc ./ex00/ft_foreach.c test_ex00_ft_foreach.c -Wall -Werror -Wextra -o test_ex00_ft_foreach
	-gcc ./ex01/ft_map.c test_ex01_ft_map.c -Wall -Werror -Wextra -o test_ex01_ft_map
	-gcc ./ex02/ft_any.c test_ex02_ft_any.c -Wall -Werror -Wextra -o test_ex02_ft_any
	-gcc ./ex03/ft_count_if.c test_ex03_ft_count_if.c -Wall -Werror -Wextra -o test_ex03_ft_count_if
	-gcc ./ex04/ft_is_sort.c test_ex04_ft_is_sort.c -Wall -Werror -Wextra -o test_ex04_ft_is_sort
	-gcc ./ex06/ft_sort_string_tab.c test_ex06_ft_sort_string_tab.c -Wall -Werror -Wextra -o test_ex06_ft_sort_string_tab
	-gcc ./ex07/ft_advanced_sort_string_tab.c test_ex07_ft_advanced_sort_string_tab.c -Wall -Werror -Wextra -o test_ex07_ft_advanced_sort_string_tab

build-sample: compile
	-./test_ex00_ft_foreach > result_sample_ex00_ft_foreach.txt
	-./test_ex01_ft_map > result_sample_ex01_ft_map.txt
	-./test_ex02_ft_any > result_sample_ex02_ft_any.txt
	-./test_ex03_ft_count_if > result_sample_ex03_ft_count_if.txt
	-./test_ex04_ft_is_sort > result_sample_ex04_ft_is_sort.txt
	-./test_ex06_ft_sort_string_tab > result_sample_ex06_ft_sort_string_tab.txt
	-./test_ex07_ft_advanced_sort_string_tab > result_sample_ex07_ft_advanced_sort_string_tab.txt

run:	compile
	-./test_ex00_ft_foreach > result_current_ex00_ft_foreach.txt
	-./test_ex01_ft_map > result_current_ex01_ft_map.txt
	-./test_ex02_ft_any > result_current_ex02_ft_any.txt
	-./test_ex03_ft_count_if > result_current_ex03_ft_count_if.txt
	-./test_ex04_ft_is_sort > result_current_ex04_ft_is_sort.txt
	-./test_ex06_ft_sort_string_tab > result_current_ex06_ft_sort_string_tab.txt
	-./test_ex07_ft_advanced_sort_string_tab > result_current_ex07_ft_advanced_sort_string_tab.txt

all:	norminette	compile run

test:	all
	-diff result_current_ex00_ft_foreach.txt result_sample_ex00_ft_foreach.txt
	-diff result_current_ex01_ft_map.txt result_sample_ex01_ft_map.txt
	-diff result_current_ex02_ft_any.txt result_sample_ex02_ft_any.txt
	-diff result_current_ex03_ft_count_if.txt result_sample_ex03_ft_count_if.txt
	-diff result_current_ex04_ft_is_sort.txt result_sample_ex04_ft_is_sort.txt
	-diff result_current_ex06_ft_sort_string_tab.txt result_sample_ex06_ft_sort_string_tab.txt
	-diff result_current_ex07_ft_advanced_sort_string_tab.txt result_sample_ex07_ft_advanced_sort_string_tab.txt

clean:
	-rm -rf */*.out
	-rm -rf result_current_ex*.txt
	-rm test_ex00_ft_foreach
	-rm test_ex01_ft_map
	-rm test_ex02_ft_any
	-rm test_ex03_ft_count_if
	-rm test_ex04_ft_is_sort
	-rm test_ex06_ft_sort_string_tab
	-rm test_ex07_ft_advanced_sort_string_tab

clean-sample:
	-rm -rf result_sample_ex*.txt

clean-before-push-with-sample: clean
	-git add .
	-git commit -m "Build Sample Complete"
	-git push origin master
