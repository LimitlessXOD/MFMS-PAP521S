typedef struct {
  int id;
  char name[50];
  char type[30];
  double purchaseValue;
  char department[50];
  char condition[30];
} Asset;

void addAsset(void);
void displayAssets(void);
void searchAsset(void);