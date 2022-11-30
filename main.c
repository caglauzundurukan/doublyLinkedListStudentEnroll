#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct ogrenci{
    int ogrenci_no;
    char ad[40];
    char soyad[40];
    char bolum[80];
    int sinif;
    struct ogrenci * next;
    struct ogrenci * prev;
};

typedef struct ogrenci node;

node* ekle (node * head){
    node * ogr =(node * )malloc(sizeof(node));
    printf("Ogrenci No: "); scanf("%d", &ogr->ogrenci_no);
    printf("Ad: "); scanf("%s", &ogr->ad);
    printf("Soyad: "); scanf("%s", &ogr->soyad);
    printf("Bolum: "); scanf("%s", &ogr->bolum);
    printf("Sinif: "); scanf("%d", &ogr->sinif);

    if(head == NULL){
        head = ogr;
        head->next=NULL;
        head->prev=NULL;
        printf("Liste olusturuldu, %d numarali ogrenci kayit edildi\n.", ogr->ogrenci_no);
    }
    else{
        ogr->next = head;
        head->prev= ogr;
        head = ogr;
        head->prev= NULL;
        printf("%d numarali ogrenci kayit edildi\n.", &ogr->ogrenci_no);
    }
    return head;
}


node* sil (node * head){
    if(head == NULL){
        printf("Liste bos, silinecek ogrenci yoktur\n");
    }
    else{
        int ogrNo;
        printf("Ogrenci No: "); scanf("%d", &ogrNo);
        if(head->ogrenci_no == ogrNo && head->next == NULL){
                free(head);
                head = NULL;
                printf("Listedeki tum ogrenciler silindi\n");
        }
        else if(head->ogrenci_no == ogrNo && head->next != NULL){
            node *p = head->next;
            free(head);
            head = p;
            p->prev = NULL;
            printf("%d numarali ogrenci silindi\n", ogrNo);

        }
        else{
            node *p = head;
            while(p->next != NULL){
                
                p = p->next;
                if(p->ogrenci_no == ogrNo){
                    node *p3 = p->next;
                    node *p2 = p->prev;
                    free(p);
                    p2->next = p3;
                    p3->prev = p2;
                    printf("%d numarali ogrenci silindi\n", ogrNo);
                    break;
                }
            }
        }
    }
    return head;
}


node* yazdir (node * head){
    //system("cls");
    if(head == NULL){
        printf("Liste bos, herhangi bir ogrenci kaydi yok.\n");
    }
    else{
        node *p = head;
        while(p!=NULL)
        {
          printf("*");
          printf("Ogrenci No: %d Ad: %s Soyad: %s Bolum: %s Sinif: %d \n ", p->ogrenci_no, p->ad, p->soyad, p->bolum, p->sinif );
          p = p->next;
        }
    }
    return head;
}





int main()
{
    int secim;
    node *head = NULL;
    while(1){
        printf("Cift yonlu dogrusal bagli liste ile ogrenci kaydi uygulamasi \n");
        printf("1-- Ogrenci Ekle \n");
        printf("2-- Ogrenci Sil \n");
        printf("3-- Listeyi Yazdir \n");
        printf("4-- Cikis \n");
        printf("Seciminizi yapin [1-4] \n");
        scanf("%d", &secim);

        switch(secim){

             case 1: head = ekle(head);
             break;

             case 2: head = sil(head);
             break;

             case 3: head = yazdir(head);
             break;

             case 4: exit(4);
             break;
             default : printf("Hatali Secim Yaptiniz! \n");
        }
  }
  
  return 0;
}
