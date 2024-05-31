unsigned char media(unsigned char* in, int i, int j, int w, int h){
    if(i < 2 || i > h-2 || j < 2 || j > w-2) return in[i*w + j];
    unsigned int somma = 0;
    for(int k1 = i-2; k1 <= i+2; k1++){
        for(int k2 = j-2; k2 <= j+2; k2++){
            somma += in[(k1*w)+k2];
            //somma = 255;
        }
    }
    somma /= 25;
    return (unsigned char) somma;
}

void blur5(unsigned char* in, unsigned char* out, int w, int h){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            out[i*w + j] = media(in, i, j, w, h);
        }
    }
}

