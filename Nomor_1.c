#include <stdio.h>

// Fungsi untuk menghitung hambatan total dari dua resistor yang dihubungkan secara paralel
float Parallel(float r1, float r2) {
    return (r1 * r2) / (r1 + r2);
}

// Fungsi untuk menghitung hambatan total dari dua resistor yang dihubungkan secara seri
float Seri(float r1, float r2) {
    return r1 + r2;
}

int main() {
    float r1 = 2, r2 = 4, r3 = 6, r4 = 3, r5 = 5, r6 = 3, r7 = 2, v = 18;
    float rp1, rs1, rp2, rs2, rp3, It, i1, is2, i4, is1, i5, i7;

    // Hitung rp1 (r5 dan r7 dihubungkan secara paralel)
    rp1 = Parallel(r5, r7);

    // Hitung rs1 (rp1 dan r6 dihubungkan secara seri)
    rs1 = Seri(rp1, r6);

    // Hitung rp2 (rs1 dan r4 dihubungkan secara paralel)
    rp2 = Parallel(rs1, r4);

    // Hitung rs2 (r2, r3, dan rp2 dihubungkan secara seri)
    rs2 = Seri(Seri(r2, r3), rp2);

    // Hitung rp3 (rs2 dan r1 dihubungkan secara paralel)
    rp3 = Parallel(rs2, r1);

    // Menghitung I total
    It = v / rp3;

    i1 = (rs2 / (r1 + rs2)) * It;

    // Hitung is2
    is2 = It - i1;

    // Hitung i4
    i4 = (rs1 / (rs1 + r4)) * is2;

    // Hitung is1
    is1 = is2 - i4;

    // Hitung i5
    i5 = (r7 / (r5 + r7)) * is1;

    // Hitung i7
    i7 = rp1 - i5;

    printf("Hambatan total (rp3): %.2lf ohm\n", rp3);
    printf("Arus total (It) = %.2lf A\n", It);
    printf("i1: %.2lf A\n", i1);
    printf("i2: %.2lf A\n", is2);
    printf("i3: %.2lf A\n", is2);
    printf("i4: %.2lf A\n", i4);
    printf("i5: %.2lf A\n", i5);
    printf("i6: %.2lf A\n", is1);
    printf("i7: %.2lf A\n", i7);

    return 0;
}