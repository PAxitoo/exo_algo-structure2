void find_occu(char tab[TAB_SIZE], int buf[TAB_SIZE][2], int *taille){
    int nb_occu = *taille;
    for(int i = 0; i < TAB_SIZE; i++){
        int temp = i;
        if(tab[temp]== 'C'){
            while(tab[temp]== 'C'){
                temp++;
            }
            if(tab[temp]== 'X'){
                temp++;
                if(tab[temp]== 'A'){
                    buf[nb_occu][0] = i;
                    buf[nb_occu][1] = temp;
                    nb_occu++;
                }
            }
            else if(tab[temp]== 'A'){
                buf[nb_occu][0] = i;
                buf[nb_occu][1] = temp;
                nb_occu++;
            }
               
        }
    }
    *taille = nb_occu;
}