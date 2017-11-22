#include <stdio.h>
#include <unistd.h>

int main() {

  int pipe1[2];
  int pipe2[2];
  int f;
  int READ = 0;
  int WRITE = 1;

  pipe(pipe1);
  pipe(pipe2);

  f = fork();
  if (f) {
    close(pipe1[READ]);
    close(pipe2[WRITE]);

    int n = 6;
    write(pipe1[WRITE], &n, sizeof(n));
    printf("[parent] sending : %d\n", n);

    read(pipe2[READ], &n, sizeof(n));
    printf("[parent] receiving: %d\n", n);

  } else {

    // Child
    close(pipe1[WRITE]);
    close(pipe2[READ]);

    int i;
    read(pipe1[READ], &i, sizeof(i));
    printf("[child] doing maths on: %d\n", i);

    i = i * 25;
    write(pipe2[WRITE], &i, sizeof(i));

  }

  return 0;
}
