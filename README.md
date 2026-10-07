# Extract-Skeleton
erosion으로 반복적으로 축소하면서 각 단계에서 opening 후에도 복원되지 않는 영역을 difference로 추출. differnce를 누적하여 skeleton 생성
# Erosion
- 객체의 바깥 경계를 반복적으로 제거하여 형태를 점점 안쪽으로 축소
- 반복할수록 객체의 중심부에 가까운 구조만 남게됨
# Opening
- erosion 결과에  erosion , dilation 적용
- 큰 구조는 복원되지만, 현재 scale에서 더 이상 유지되지 못하는 얇은 구조는 사라짐
# Difference extraction
- erosion 결과와 opening 결과의 차이를 계산
- 현재 객체에는 존재하지만 한번더 erosion, dilation 했을때 복원하면 사라지는 부분 추출
- 이 영역은 해당 scale에서 객체의 형태와 두께를 표현하는 중심구조로 볼 수 있음.
# Skeleton accumulation
- erosion 단계에서 얻은 difference 를 누적
# img1 , result

<img width="251" height="100" alt="sk1" src="https://github.com/user-attachments/assets/6687a2ba-a3d8-4891-8b90-632ac2754d98" />       <img width="251" height="100" alt="sk1_res" src="https://github.com/user-attachments/assets/579e40f9-9d3a-423c-9f9a-ccef213d1343" />

# img2 ,result

<img width="219" height="106" alt="sk2" src="https://github.com/user-attachments/assets/e5191411-12ba-4333-ba78-4142cbc0187a" /> <img width="219" height="106" alt="sk2_res" src="https://github.com/user-attachments/assets/1c026da5-8c31-497d-85ba-ed6a7fe371b3" />

# img3,result

<img width="296" height="94" alt="sk3" src="https://github.com/user-attachments/assets/5bbe4ab6-84ed-430a-b4a4-a09cf54ff459" />  <img width="296" height="94" alt="sk3_res" src="https://github.com/user-attachments/assets/bfc989ca-667f-4953-b800-98675110ab1b" />



