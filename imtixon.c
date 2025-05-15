#include <stdio.h>
#include <string.h>

#define MAX_TAOM 100

typedef struct {
    char nomi[50];
    float narx;
    int sotilgan;
} Taom;

Taom menyu[MAX_TAOM];
int taom_soni = 0;

void eng_arzon_taom();
void eng_qimmat_taom();
void eng_kop_sotilgan();
void narx_boyicha_qidirish();
void nom_boyicha_qidirish();
void buyurtma_tarixi_saqlash();
void barcha_taomlarni_korish();

void print_table_header() {
    printf("+----+----------------------+----------+------------+\n");
    printf("| №  | Taom nomi            | Narxi    | Sotilgan   |\n");
    printf("+----+----------------------+----------+------------+\n");
}

void print_row(int index, Taom t) {
    printf("| %-2d | %-20s | %-8.0f | %-10d |\n", index + 1, t.nomi, t.narx, t.sotilgan);
}

void barcha_taomlarni_korish() {
    if (taom_soni == 0) {
        printf("Menyuda hali taomlar yo‘q.\n");
        return;
    }

    print_table_header();
    for (int i = 0; i < taom_soni; i++) {
        print_row(i, menyu[i]);
    }
    printf("+----+----------------------+----------+------------+\n");
}

// Quyidagi funksiyalar realizatsiyasi:

void eng_arzon_taom() {
    int minIndex = 0;
    for (int i = 1; i < taom_soni; i++) {
        if (menyu[i].narx < menyu[minIndex].narx)
            minIndex = i;
    }
    printf("Eng arzon taom: %s - %.0f so'm\n", menyu[minIndex].nomi, menyu[minIndex].narx);
}

void eng_qimmat_taom() {
    int maxIndex = 0;
    for (int i = 1; i < taom_soni; i++) {
        if (menyu[i].narx > menyu[maxIndex].narx)
            maxIndex = i;
    }
    printf("Eng qimmat taom: %s - %.0f so'm\n", menyu[maxIndex].nomi, menyu[maxIndex].narx);
}

void eng_kop_sotilgan() {
    int maxIndex = 0;
    for (int i = 1; i < taom_soni; i++) {
        if (menyu[i].sotilgan > menyu[maxIndex].sotilgan)
            maxIndex = i;
    }
    printf("Eng ko‘p sotilgan taom: %s - %d marta\n", menyu[maxIndex].nomi, menyu[maxIndex].sotilgan);
}

void narx_boyicha_qidirish() {
    float minNarx, maxNarx;
    printf("Minimal narxni kiriting: ");
    scanf("%f", &minNarx);
    printf("Maksimal narxni kiriting: ");
    scanf("%f", &maxNarx);

    printf("Narxi %.0f dan %.0f gacha bo‘lgan taomlar:\n", minNarx, maxNarx);
    for (int i = 0; i < taom_soni; i++) {
        if (menyu[i].narx >= minNarx && menyu[i].narx <= maxNarx) {
            printf("%s - %.0f so'm\n", menyu[i].nomi, menyu[i].narx);
        }
    }
}

void nom_boyicha_qidirish() {
    char qidiruv[50];
    printf("Qidirilayotgan nomni kiriting: ");
    scanf("%s", qidiruv);

    printf("Qidiruv natijasi:\n");
    for (int i = 0; i < taom_soni; i++) {
        if (strstr(menyu[i].nomi, qidiruv)) {
            printf("%s - %.0f so'm\n", menyu[i].nomi, menyu[i].narx);
        }
    }
}

void buyurtma_tarixi_saqlash() {
    FILE *fayl = fopen("tarix.txt", "w");
    if (fayl == NULL) {
        printf("Faylga yozib bo‘lmadi!\n");
        return;
    }

    for (int i = 0; i < taom_soni; i++) {
        fprintf(fayl, "%s - %.0f so'm - %d marta sotilgan\n", menyu[i].nomi, menyu[i].narx, menyu[i].sotilgan);
    }

    fclose(fayl);
    printf("Buyurtma tarixi 'tarix.txt' fayliga saqlandi.\n");
}


int main() {
    int tanlov;

    // Taomlar menyuga oldindan qo‘shiladi
    strcpy(menyu[0].nomi, "Lag'mon");     menyu[0].narx = 25000; menyu[0].sotilgan = 10;
    strcpy(menyu[1].nomi, "Osh");         menyu[1].narx = 20000; menyu[1].sotilgan = 25;
    strcpy(menyu[2].nomi, "Shashlik");    menyu[2].narx = 30000; menyu[2].sotilgan = 15;
    strcpy(menyu[3].nomi, "Somsa");       menyu[3].narx = 8000;  menyu[3].sotilgan = 30;
    strcpy(menyu[4].nomi, "Norin");       menyu[4].narx = 22000; menyu[4].sotilgan = 12;
    strcpy(menyu[5].nomi, "Manti");       menyu[5].narx = 18000; menyu[5].sotilgan = 17;
    strcpy(menyu[6].nomi, "Chuchvara");   menyu[6].narx = 16000; menyu[6].sotilgan = 20;
    strcpy(menyu[7].nomi, "Kabob");       menyu[7].narx = 28000; menyu[7].sotilgan = 11;
    strcpy(menyu[8].nomi, "Beshbarmoq");  menyu[8].narx = 35000; menyu[8].sotilgan = 9;
    strcpy(menyu[9].nomi, "Qozonkabob");  menyu[9].narx = 40000; menyu[9].sotilgan = 5;
    taom_soni = 10;

    do {
        printf("\n📋 MENU:\n");
        printf("1. Eng arzon taom\n");
        printf("2. Eng qimmat taom\n");
        printf("3. Eng ko‘p sotilgan taom\n");
        printf("4. Narxi bo‘yicha qidirish\n");
        printf("5. Nomi bo‘yicha qidirish (strstr)\n");
        printf("6. Buyurtma tarixini saqlash\n");
        printf("7. Barcha ovqatlarni ko‘rish\n");
        printf("0. Chiqish\n");
        printf("Tanlovingizni kiriting: ");
        scanf("%d", &tanlov);

        switch (tanlov) {
            case 1: eng_arzon_taom(); break;
            case 2: eng_qimmat_taom(); break;
            case 3: eng_kop_sotilgan(); break;
            case 4: narx_boyicha_qidirish(); break;
            case 5: nom_boyicha_qidirish(); break;
            case 6: buyurtma_tarixi_saqlash(); break;
            case 7: barcha_taomlarni_korish(); break;
            case 0: printf("Dastur tugadi.\n"); break;
            default: printf("Noto‘g‘ri tanlov!\n"); break;
        }
    } while (tanlov != 0);

    return 0;
}
