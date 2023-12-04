#include <stdio.h>

// Fungsi untuk menghitung hambatan total dari dua resistor yang dihubungkan secara paralel
float parallelResistance(float r1, float r2) {
    return (r1 * r2) / (r1 + r2);
}

// Fungsi untuk menghitung hambatan total dari dua resistor yang dihubungkan secara seri
float seriesResistance(float r1, float r2) {
    return r1 + r2;
}

int main() {
    float r1 = 2, r2 = 4, r3 = 6, r4 = 3, r5 = 5, r6 = 3, r7 = 2, v = 18;
    float rp1, rs1, rp2, rs2, rp3;

    // Hitung rp1 (r5 dan r7 dihubungkan secara paralel)
    rp1 = parallelResistance(r5, r7);

    // Hitung rs1 (rp1 dan r6 dihubungkan secara seri)
    rs1 = seriesResistance(rp1, r6);

    // Hitung rp2 (rs1 dan r4 dihubungkan secara paralel)
    rp2 = parallelResistance(rs1, r4);

    // Hitung rs2 (r2, r3, dan rp2 dihubungkan secara seri)
    rs2 = seriesResistance(seriesResistance(r2, r3), rp2);

    // Hitung rp3 (rs2 dan r1 dihubungkan secara paralel)
    rp3 = parallelResistance(rs2, r1);

    printf("Hambatan total (rp3): %.2f ohm\n", rp3);

    return 0;
}