#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{

// Wprowadz potrzebne dane do pliku //

system("user='wpisz_nazwe_usera'");
system("password='wpisz_haslo_uzytkownika'");
system("bazadanych='wpisz_nazwe_bazy_danych'");
system("host='wpisz_nazwe_hosta'");
system("email='wpisz_swoj_email_gdzie_ma_przyjsc_kopia'");
system("encoded='tu_wpisz_nazwe_zakodowanego_pliku'");
system("hash='haslo_do_zakodowanego_pliku'");

// W tym momencie nic nie edytuj ! //

system("/usr/bin/mysqldump -u $user -p$password -h $host $baza > $bazadanych.sql");
system("/bin/tar -czvf $bazadanych.tar.gz $bazadanych.sql");
system("rm -rf $bazadanych.sql");
system("openssl aes-256-cbc -salt -in $bazadanych.sql -out $encoded.tar.gz -k $hash");
system("rm -rf $bazadanych.tar.gz");
system("echo 'Kopia bazy danych' | /bin/mailx -s 'Kopia bazy danych strony' -a $encoded.tar.gz $email");
system("rm -rf $encoded.tar.gz");
return 0;
}
