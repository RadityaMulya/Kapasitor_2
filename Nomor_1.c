#include <stdio.h>
#include <math.h>

// Fungsi untuk menghitung hambatan total dari dua resistor yang dihubungkan secara paralel
float Parallel(float r1, float r2)
{
    return (r1 * r2) / (r1 + r2);
}

// Fungsi untuk menghitung hambatan total dari dua resistor yang dihubungkan secara seri
float Seri(float r1, float r2)
{
    return r1 + r2;
}

// Fungsi untuk menghitung kapasitor secara paralel
float parallelCapacitance(float c1, float c2)
{
    return c1 + c2;
}

// Fungsi untuk mengitung kapasitor atau c secara seri
float seriesCapacitance(float c1, float c2)
{
    return (c1 * c2) / (c1 + c2);
}

int main()
{
    float r1 = 2, r2 = 4, r3 = 6, r4 = 3, r5 = 5, r6 = 3, r7 = 2, v = 18;
    float rp1, rs1, rp2, rs2, rp3, It, i1, is2, i4, is1, i5, i7;
    float v1, v2, v3, v4, v5, v6, v7;
    float c1 = 3, c2 = 5, c3 = 4, c4 = 2, c5 = 2, c6 = 6, c7 = 5, V = 18;
    float cp1, cs1, cp2, cs2, cp3, ctotal, Qtotal, q1, qp2, q3, q4, q5, q6, q7;
    float V1, V2, V3, V4, V5, V6, V7;

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
    i7 = is1 - i5;

    v1 = i1 * r1;
    v2 = is2 * r2;
    v3 = is2 * r3;
    v4 = i4 * r4;
    v5 = i5 * r5;
    v6 = is1 * r6;
    v7 = i7 * r7;

    // Total Hambatan atau R total
    printf("Hambatan total / rtotal: %.2lf ohm\n", rp3);

    // Arus Total
    printf("Arus total (It) = %.2lf A\n", It);

    // Total I1 - I7
    printf("i1: %.2lf A\n", i1);
    printf("i2: %.2lf A\n", is2);
    printf("i3: %.2lf A\n", is2);
    printf("i4: %.2lf A\n", i4);
    printf("i5: %.2lf A\n", i5);
    printf("i6: %.2lf A\n", is1);
    printf("i7: %.2lf A\n", i7);

    // Total V1 - V7
    printf("v1: %.2f V\n", v1);
    printf("v2: %.2f V\n", v2);
    printf("v3: %.2f V\n", v3);
    printf("v4: %.2f V\n", v4);
    printf("v5: %.2f V\n", v5);
    printf("v6: %.2f V\n", v6);
    printf("v7: %.2f V\n", v7);

    // Hitung cp1 (c5 dan c7 dihubungkan secara paralel)
    cp1 = parallelCapacitance(c5, c7);

    // Hitung cs1 (cp1 dan c6 dihubungkan secara seri)
    cs1 = seriesCapacitance(cp1, c6);

    // Hitung cp2 (cs1 dan c4 dihubungkan secara paralel)
    cp2 = parallelCapacitance(cs1, c4);
    printf("cp2 = %.2f V\n", cp2);
    // Hitung cs2 (cp2, c2, dan c3 dihubungkan secara seri)
    cs2 = seriesCapacitance(seriesCapacitance(cp2, c2), c3) * 1;
    printf("cs2 = %.2f\n", cs2);
    
    // Hitung cp3 (cs2 dan c1 dihubungkan secara paralel)
    cp3 = seriesCapacitance(c1, cs2);

    // Kapasitansi total adalah cp3
    ctotal = cp3;

    // Hitung Q total
    Qtotal =  V * ctotal;

    // Hitung Q1 - Q7
    q1 = (cs1 / (cs1 + c4)) * Qtotal;
    qp2 = Qtotal - q1; // qp2 = q2 = q3
    q4 = (cs1 /  (cs1 + c4)) * qp2;
    q6 = qp2 - q4;
    q5 = (c7 / (c5 + c7)) * q6;
    q7 = q6 - q5;

    V1 = q1 - c1;
    V2 = qp2 - c2;
    V3 = qp2 - c3;
    V4 = q4 - c4;
    V5 = q5 - c5;
    V6 = q6 - c6;
    V7 = q7 - c7;

    printf("Kapasitansi total (Ctotal): %.2f F\n", ctotal);
    printf("Qtotal : %.2f C\n", Qtotal);
    printf("q1: %.2f C\n", q1);
    printf("q2: %.2f C\n", qp2);
    printf("q3: %.2f C\n", qp2);
    printf("q4: %.2f C\n", q4);
    printf("q6: %.2f C\n", q6);
    printf("q5: %.2f C\n", q5);
    printf("q7: %.2f C\n", q7);
    printf("v1: %.2f V\n", V1);
    printf("v2: %.2f V\n", V2);
    printf("v3: %.2f V\n", V3);
    printf("v4: %.2f V\n", V4);
    printf("v5: %.2f V\n", V5);
    printf("v6: %.2f V\n", V6);
    printf("v7: %.2f V\n", V7);

    return 0;
}