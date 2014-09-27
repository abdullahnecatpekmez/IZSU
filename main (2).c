#include <stdio.h>
#include <stdlib.h>

int main()
{
    int abone_kodu, gun_say;
    int konut_say=0, isyeri_say=0, kamu_say=0, ttesis_say=0, top_abone=0;
    int kon_gun_top=0, isyeri_gun_top=0, kamu_gun_top=0, ttesis_gun_top=0, kad1_kon_say=0, kad2_isyeri_say=0;
    double kon_top_tuke=0, isyeri_top_tuke=0, kamu_top_tuke=0, ttesis_top_tuke=0, top_ay_atik_uc=0,  ay_top_KDV_uc=0;
    double kon_ay_top_tuke=0, isyeri_ay_top_tuke=0, kamu_ay_top_tuke=0, ttesis_ay_top_tuke=0, izmir_ay_top_tuke=0;
    double kon_ay_top_tuke_uc=0, isyeri_ay_top_tuke_uc=0, kamu_ay_top_tuke_uc=0, ttesis_ay_top_tuke_uc=0, ay_top_tuke_uc=0, gun_kon_tuke_max=0;
    float on_say_deg, sim_say_deg, toplam_tut, gun_kon_tuke_ort, gunluk_isyeri_ort, gunluk_kon_ort;
    double atik_su_ucreti, tuketim, su_tuke_ucreti, KDV, konut_yuz, isyeri_yuz, kamu_yuz, ttesis_yuz, kad1_kon_yuz, kad2_isyeri_yuz;
    float  kon_gun_tuke_ort, isyeri_gun_tuke_ort, kamu_gun_tuke_ort, ttesis_gun_tuke_ort;
    char devam;
    do{

          printf("Abone tipi kodunu giriniz:\n");
          printf("[1:konut,2:isyeri,3:kamu kurumu,4:turistik tesis]:");
          scanf("%d", &abone_kodu);
          while (abone_kodu>4 || abone_kodu<=0){
               printf("Lutfen 1 ile 4 arasinda bir sayi giriniz!\n");
               printf("Abone tipi kodununu tekrar giriniz:\n");
               printf("[1:konut,2:isyeri,3:kamu kurumu,4:turistik tesis]:");
               scanf("%d", &abone_kodu);
          }
          printf("Onceki sayac degerini giriniz:");
          scanf("%f", &on_say_deg);

          printf("Simdiki sayac degerini giriniz:");
          scanf("%f", &sim_say_deg);

          printf("Onceki ve simdiki okuma tarihleri arasinda gecen gun sayisini giriniz:");
          scanf("%d", &gun_say);

          tuketim=sim_say_deg-on_say_deg;
          top_abone=top_abone+1;

          izmir_ay_top_tuke=izmir_ay_top_tuke+tuketim;//izmirin aylýk su tuketim miktari


         if(abone_kodu==1){

               printf("Abone Tipi:Konut\n");
               atik_su_ucreti=tuketim*1.91;
               konut_say=konut_say+1;
               kon_top_tuke=kon_top_tuke+tuketim;
               kon_gun_top=kon_gun_top+gun_say;
               gun_kon_tuke_ort=tuketim/gun_say;//konut abonesinin gunluk su tuketim ortalamasý
               if (gun_kon_tuke_ort>gun_kon_tuke_max){//gunluk su ortalamasý max olan abone
                   gun_kon_tuke_max=gun_kon_tuke_ort;
                   }
               kon_ay_top_tuke=kon_ay_top_tuke+tuketim;//konut abonelerinin toplam aylýk su tuketim miktari
               gunluk_kon_ort=tuketim/gun_say;

               if(gunluk_kon_ort>=0 && gunluk_kon_ort<=0.43){
                     su_tuke_ucreti=tuketim*2.24;
                     kad1_kon_say=kad1_kon_say+1;//1.kademeyi asmayan konut abonelerinin sayisi

                    }
               else{
                     if(gunluk_kon_ort>=0.46 && gunluk_kon_ort<=0.66){
                         su_tuke_ucreti=tuketim*5.78;

                        }
                     else
                         su_tuke_ucreti=tuketim*9.33;
                     }
                 kon_ay_top_tuke_uc=kon_ay_top_tuke_uc+su_tuke_ucreti;
                }

         else{
               if(abone_kodu==2){

                     printf("Abone Tipi:Is Yeri\n");
                     atik_su_ucreti=tuketim*3.79;
                     isyeri_say=isyeri_say+1;
                     isyeri_top_tuke=isyeri_top_tuke+tuketim;
                     isyeri_gun_top=isyeri_gun_top+gun_say;
                     isyeri_ay_top_tuke=isyeri_ay_top_tuke+tuketim;//isyeri abonelerinin toplam aylýk su tuketim miktari
                     gunluk_isyeri_ort=tuketim/gun_say;

                     if(gunluk_isyeri_ort>=0 && tuketim/gun_say<=0.33){
                         su_tuke_ucreti=tuketim*7.71;
                     }

                     else{
                         su_tuke_ucreti=tuketim*8.88;
                         kad2_isyeri_say=kad2_isyeri_say+1;
                        }
                     isyeri_ay_top_tuke_uc=isyeri_ay_top_tuke_uc+su_tuke_ucreti;//isyeri abonelerinin aylýk toplam su tuketim ucreti
                     }

               else{
                     if(abone_kodu==3){

                          printf("Abone Tipi:Kamu Kurulusu\n");
                          atik_su_ucreti=tuketim*2.56;
                          su_tuke_ucreti=tuketim*6.64;
                          kamu_say=kamu_say+1;
                          kamu_top_tuke=kamu_top_tuke+tuketim;
                          kamu_gun_top=kamu_gun_top+gun_say;
                          kamu_ay_top_tuke=kamu_ay_top_tuke+tuketim;//kamu kurulusu abonelerinin toplam aylýk su tuketim miktari
                          kamu_ay_top_tuke_uc=kamu_ay_top_tuke_uc+su_tuke_ucreti;//kamu abonelerinin aylýk toplam su tuketim ucreti
                     }

                     else{

                          printf("Abone Tipi:Turistik Tesis\n");
                          atik_su_ucreti=tuketim*1.91;
                          su_tuke_ucreti=tuketim*5.78;
                          ttesis_say=ttesis_say+1;
                          ttesis_top_tuke=ttesis_top_tuke+tuketim;
                          ttesis_gun_top=ttesis_gun_top+gun_say;
                          ttesis_ay_top_tuke=ttesis_ay_top_tuke+tuketim;//turistik tesis abonelerinin toplam aylýk su tuketim miktari
                          ttesis_ay_top_tuke_uc=ttesis_ay_top_tuke_uc+su_tuke_ucreti;//turistik tesis abonelerinin aylýk toplam su tuketim ucreti

                         }
               }
            ay_top_tuke_uc=ay_top_tuke_uc+su_tuke_ucreti;//aylýk toplam su tuketim ucreti
            top_ay_atik_uc=top_ay_atik_uc+atik_su_ucreti;//tüm abonelerden elde edilen aylýk toplam atýk su ücreti

         }
         printf("Aylik su tuketim miktari:%.2f\n", tuketim);
         printf("Aylik su tuketim ucreti:%.2f\n", su_tuke_ucreti);
         printf("Aylik atik su ucreti:%.2f\n", atik_su_ucreti);
         KDV=(su_tuke_ucreti+atik_su_ucreti)*8/100;
         printf("Aylik KDV tutari:%.2f\n", KDV);
         toplam_tut=su_tuke_ucreti+atik_su_ucreti+KDV;
         printf("Aylik toplam fatura tutari:%.2f\n", toplam_tut);
         ay_top_KDV_uc=ay_top_KDV_uc+KDV;//devlete ödenen aylýk toplam KDV tutarý


          do{
            printf("Baska bir aboneye dair islem yapmak istiyor musunuz?(e/E/h/H)?");
            fflush(stdin);
            devam=getchar();
         }while (devam!='e' && devam!='E' && devam!='h' && devam!='H');
         if (devam=='h' || devam=='H'){
              break;
            }
    }while(on_say_deg>=0 && on_say_deg<=sim_say_deg && gun_say>=0);
    printf("Konut abonelerinin sayisi:%d\n", konut_say);
    printf("Isyeri abonelerinin sayisi:%d\n", isyeri_say);
    printf("Kamu kurulusu abonelerinin sayisi:%d\n", kamu_say);
    printf("Turistik tesis abonelerinin sayisi:%d\n", ttesis_say);

    konut_yuz=konut_say*100/top_abone;
    printf("Konut abonelerinin yuzdesi:%.2f\n", konut_yuz);
    isyeri_yuz=isyeri_say*100/top_abone;
    printf("Isyeri abonelerinin yuzdesi:%.2f\n", isyeri_yuz);
    kamu_yuz=kamu_say*100/top_abone;
    printf("Kamu abonelerinin yuzdesi:%.2f\n", kamu_yuz);
    ttesis_yuz=ttesis_say*100/top_abone;
    printf("Turistik tesis abonelerinin yuzdesi:%.2f\n", ttesis_yuz);

    kon_gun_tuke_ort=kon_top_tuke/kon_gun_top;
    printf("Konut abonelerinin gunluk ortalama su tuketim miktari:%.2f\n", kon_gun_tuke_ort);
    isyeri_gun_tuke_ort=isyeri_top_tuke/isyeri_gun_top;
    printf("Isyeri abonelerinin gunluk ortalama su tuketim miktari:%.2f\n", isyeri_gun_tuke_ort);
    kamu_gun_tuke_ort=kamu_top_tuke/kamu_gun_top;
    printf("Kamu kurulusu abonelerinin gunluk ortalama su tuketim miktari:%.2f\n", kamu_gun_tuke_ort);
    ttesis_gun_tuke_ort=ttesis_top_tuke/ttesis_gun_top;
    printf("Turistik tesis abonelerinin gunluk ortalama su tuketim miktari:%.2f\n", ttesis_gun_tuke_ort);

    printf("1.kademeyi asmayan(0-13 ton arasi) konut abonelerinin sayisi:%d\n", kad1_kon_say);
    kad1_kon_yuz=kad1_kon_say*100/top_abone;
    printf("1.kademeyi asmayan(0-13 ton arasi) konut abonelerinin yuzdesi:%.2f\n", kad1_kon_yuz);

    printf("1.kademeyi asan(11 ton ve uzeri) isyeri abonelerinin sayisi:%d\n", kad2_isyeri_say);
    kad2_isyeri_yuz=kad2_isyeri_say*100/top_abone;
    printf("1.kademeyi asmayan(11 ton ve uzeri) isyeri abonelerinin yuzdesi:%.2f\n", kad2_isyeri_yuz);

    printf("Gunluk ortalama su tüketim miktari en yüksek olan konut tipi abonenin gunluk ortalama su tüketim miktari:%.2f\n", gun_kon_tuke_max);

    printf("Aylik toplam su tuketim miktarlari:\n");
    printf("Konut:%.2f\n", kon_ay_top_tuke);
    printf("Isyeri:%.2f\n", isyeri_ay_top_tuke);
    printf("Kamu Kurulusu:%.2f\n", kamu_ay_top_tuke);
    printf("Turistik Tesis:%.2f\n", ttesis_ay_top_tuke);
    printf("Izmir Toplam:%.2f\n", izmir_ay_top_tuke);

    printf("Aylik toplam su tüketim ucretleri:\n");
    printf("Konut:%.2f\n", kon_ay_top_tuke_uc);
    printf("Isyeri:%.2f\n", isyeri_ay_top_tuke_uc);
    printf("Kamu Kurulusu:%.2f\n", kamu_ay_top_tuke_uc);
    printf("Turistik Tesis:%.2f\n", ttesis_ay_top_tuke_uc);
    printf("Izmir Toplam:%.2f\n", ay_top_tuke_uc);

    printf("Tum abonelerden elde edilen aylik toplam atik su ucreti:%.2f\n", top_ay_atik_uc);

    printf("Devlete odenen aylik toplam KDV tutari:%.2f\n", ay_top_KDV_uc);

  return 0;
}
