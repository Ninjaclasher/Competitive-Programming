#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef uint8_t byte;
typedef uint16_t u16;
typedef int32_t s32;
typedef uint32_t u32;
typedef uint64_t u64;
typedef _Bool bool;

#ifdef DEBUG
#  define debug(...) ({fprintf(stderr,__VA_ARGS__);fflush(stderr);})
#else
#  define NDEBUG
#  define debug(...)
#endif

static const u32 MOD = 1000000007;

/* Square matrices only please */
static void mmmul(const u32 N,u32 c[N][N],u32 a[N][N],u32 b[N][N])
{
 for(u32 i = 0;i < N;i++)
 {
  for(u32 j = 0;j < N;j++)
  {
   c[i][j] = 0;
   for(u32 k = 0;k < N;k++)
    c[i][j] = (c[i][j] + (u64)a[i][k] * b[k][j]) % MOD;
  }
 }
}

static void mvmul(const u32 N,u32 c[N],u32 a[N],u32 b[N][N])
{
 for(u32 i = 0;i < N;i++)
 {
  c[i] = 0;
  for(u32 j = 0;j < N;j++)
   c[i] = (c[i] + (u64)a[j] * b[i][j]) % MOD;
 }
}

#define swap(a,b) ({__typeof(a) _ = a;a = b;b = _;})

int main(void)
{
 u32 N;
 byte* Z;
 scanf("%u %ms",&N,&Z);
 u32 (*m)[N][N] = malloc(9 * sizeof(*m));
 --m;
 memset(m[1],0,sizeof(m[1]));
 for(u32 i = 0;i < N - 1;i++)
  m[1][i][i + 1] = 1;
 for(u32 i = 0;i < N;i++)
  scanf(" %u",&m[1][N - 1][N - 1 - i]);
 u32 lZ = strlen(Z);
 if(lZ < 20)
 {
  u64 z;
  sscanf(Z,"%lu",&z);
  if(z <= N)
  {
   printf("1\n");
   return 0;
  }
  /* Use other algorithm for testing purposes */
goto label00;
  u32 (*ma)[N] = m[1];
  u32 (*mb)[N] = m[2];
  u32* va = malloc(N * sizeof(*va));
  for(u32 i = 0;i < N;i++)
   va[i] = 1;
  u32* vb = malloc(N * sizeof(*vb));
  z -= N;
  do
  {
   if(z & 1)
   {
    mvmul(N,vb,va,ma);
    swap(va,vb);
   }
   mmmul(N,mb,ma,ma);
   swap(ma,mb);
  }
  while(z >>= 1);
  printf("%u\n",va[N - 1]);
 }
 else
 {
label00:
  for(u32 i = 0;i < lZ;i++)
   Z[i] ^= '0';
  u32 i = lZ - 1;
  while(Z[i] == 0)
   Z[i--] = 9;
  --Z[i];
  i = 0;
  while(Z[i] == 0)
   i++;
  for(u32 i = 2;i <= 9;i++)
   mmmul(N,m[i],m[i - 1],m[1]);
  u32 (*ma)[N] = malloc(N * sizeof(*ma));
  u32 (*mb)[N] = malloc(N * sizeof(*mb));
  u32 (*mc)[N] = malloc(N * sizeof(*mc));
  memset(ma,0,sizeof(m[0]));
  for(u32 i = 0;i < N;i++)
   ma[i][i] = 1;
  for(;i < lZ;i++)
  {
   mmmul(N,mb,ma,ma);
   if(Z[i])
   {
    mmmul(N,mc,mb,mb);
    mmmul(N,ma,mc,mc);
    mmmul(N,mc,ma,mb);
    mmmul(N,ma,mc,m[Z[i]]);
   }
   else
   {
    mmmul(N,ma,mb,mb);
    mmmul(N,mc,ma,ma);
    mmmul(N,ma,mb,mc);
   }
  }
  u32 k = 0;
  for(u32 i = 0;i < N;i++)
   k = (k + ma[0][i]) % MOD;
  printf("%u\n",k);
 }
 return 0;
}

/* inspired by Andy Pham */
