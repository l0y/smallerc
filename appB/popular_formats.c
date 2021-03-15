#include <stdio.h>

int main() {
  char answer = 'y';
  int count = 76;
  int gap = -12;
  unsigned long long debt = 28054511505742;
  float balance = 216.29;
  char name[] = "Ada Lovelace";

  printf("char Examples\n");
  printf("  Simple char:             %%c       |%c|\n", answer);
  printf("  In a 9-char field:       %%9c      |%9c|\n", answer);
  printf("  Left, 9-char field:      %%-9c     |%-9c|\n", answer);
  printf("  The percent sign:        %%%%       |%%|\n");

  printf("\n\nint Examples\n");
  printf("  Simple int:              %%i       |%i|\n", count);
  printf("  Simple decimal int:      %%d       |%d|\n", count);
  printf("  Simple octal int:        %%o       |%o|\n", count);
  printf("  Prefixed octal int:      %%#o      |%#o|\n", count);
  printf("  Simple hexadecimal int:  %%x       |%x|\n", count);
  printf("  Uppercase hexadecimal:   %%X       |%X|\n", count);
  printf("  Prefixed hexadecimal:    %%#x      |%#x|\n", count);
  printf("  Prefixed uppercase:      %%#X      |%#X|\n", count);
  printf("  In a 9-column field:     %%9i      |%9i|\n", count);
  printf("  Left, 9-column field:    %%-9i     |%-9i|\n", count);
  printf("  Zeros, 9-column field:   %%09i     |%09i|\n", count);
  printf("  With plus prefix:        %%+i      |%+i|\n", count);
  printf("    negative value:                 |%+i|\n", gap);
  printf("  With space prefix:       %% i      |% i|\n", count);
  printf("     negative value:                |% i|\n", gap);
  printf("  Huge number:             %%llu     |%llu|\n", debt);
  printf("  (Ignored) precision:     %%1.1d    |%1.1d|\n", count);

  printf("\n\nfloat Examples\n");
  printf("  Simple float:            %%f       |%f|\n", balance);
  printf("  2 decimal places:        %%.2f     |%.2f|\n", balance);
  printf("  1 decimal place:         %%.1f     |%.1f|\n", balance);
  printf("  No decimal places:       %%.0f     |%.0f|\n", balance);
  printf("  In a 12-column field:    %%12f     |%12f|\n", balance);
  printf("  2 decimals, 12 columns:  %%12.2f   |%12.2f|\n", balance);
  printf("  Left, 12-column field:   %%-12.2f  |%-12.2f|\n", balance);

  printf("\n\nstring (char[]) Examples\n");
  printf("  Simple string:           %%s       |%s|\n", name);
  printf("  In a 20-column field:    %%20s     |%20s|\n", name);
  printf("  Left, 20-column field:   %%-20s    |%-20s|\n", name);
  printf("  6-column field:          %%6s      |%6s|\n", name);
  printf("  6-columns, truncated:    %%6.6s    |%6.6s|\n", name);

  printf("\n\nAnd last but not least, a blank line (\\n):\n");
  printf("\n");
}

