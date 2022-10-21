#include <stdio.h>

int main() {
    
    FILE* fp = fopen("income.txt", "w");
    
    const int start_age, end_age = 60;        //취업시작나이, 정년나이
    const double start_salary;                //초봉
    const double growth_ratio;                //연봉 상승률

    printf("취업 연령 : ");
    scanf("%d", &start_age);
    printf("\n");

    printf("사망 연령 : ");
    scanf("%d", &end_age);
    printf("\n");

    printf("초봉 : ");
    scanf("%lf", &start_salary);
    printf("\n");

    printf("임금 상승률 : ");
    scanf("%lf", &growth_ratio);
    printf("\n");

    double annual_salary = start_salary;
    double income_sum = 0;                          
    double salary_sum = 0;  
    int age;                    

    for(age = start_age; age < 55; age++, annual_salary *= (1.0 + growth_ratio))
    {
        income_sum += annual_salary;
        salary_sum += annual_salary;
        printf("나이 : %d, 연봉 : %f , 누적소득 : %f\n", age, annual_salary, income_sum);
        //fprintf(fp, "%d  %f %f \n", age, annual_salary, income_sum);
        fprintf(fp, "%f\n", income_sum);
    }
    
    annual_salary *= 0.5;                                                       //55세부턴 임금의 50% 지급.
    for(age = 55; age <= 60; age++) {
        income_sum += annual_salary;
        printf("나이 : %d, 연봉 : %f , 누적소득 : %f\n", age, annual_salary, income_sum);
        //fprintf(fp, "%d  %f %f \n", age, annual_salary, income_sum);
        fprintf(fp, "%f\n", income_sum);
    }

    const double salary_average = salary_sum / (double)(60 - start_age + 1);    //전체 재직기간 평균 연봉

    for(age = 61; age <= end_age; age++) {
        income_sum += salary_average * 0.45;                                    //61세부턴 임금피크제 적용하여 연봉 감소
        printf("나이 : %d, 연봉 : %f , 누적소득 : %f\n", age, annual_salary, income_sum);
        //fprintf(fp, "%d %f %f \n", age, annual_salary, income_sum);
        fprintf(fp, "%f\n", income_sum);
    }
    fclose(fp);
}