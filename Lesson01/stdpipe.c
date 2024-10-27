#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  char string_stdout[] = "Hello World from STDOUT\n";
  char string_stderr[] = "Hello World from STDERR\n";

  write(1, string_stdout, sizeof(string_stdout));
  write(2, string_stderr, sizeof(string_stderr));

  int ret = close(1);
  if (ret == -1) {
    perror("close error!");
    return 1;
  }

  write(1, string_stdout, sizeof(string_stdout));
  write(2, string_stderr, sizeof(string_stderr));

  return 0;
}
