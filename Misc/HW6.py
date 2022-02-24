# HW6_LIST (ไม่ลบหรือแก้ไขบรรทัดนี้ หรือเพิ่มอะไรก่อนบรรทัดนี้ โดยเด็ดขาด)

# - เขียนในเซลล์นี้เท่านั้น 
# - ถ้าต้องการเขียนฟังก์ชันเพิ่ม ก็เขียนในเซลล์นี้

def compute_similarity(food_name1, food_name2):
  #"""
  #รับ food_name1 และ food_name2 เป็นสตริงเก็บชื่ออาหารที่ตัดคำมาให้แล้ว โดยมีวรรคคั่นระหว่างคำ
  #คืน ค่าความคล้ายของชื่ออาหาร ซึ่งเป็นเลขจำนวนจริงที่มีค่าระหว่าง [0,1]
  #"""
    F1 = food_name1.split()
    F2 = food_name2.split()
    ma = 0
    for i in F1 :
        if i in F2 :
            ma += 1
    sm = ma*2/(len(F1)+len(F2))

    return sm

# ---------------------------------------------------
def match_foods(nutrient, food_name):
  #"""
  #รับ nutrient เก็บตารางข้อมูลโภชนาการรูปแบบของลิสต์ที่อธิบายข้างบน
  #รับ food_name เป็นสตริงชื่ออาหารที่ผู้บริโภครับประทานที่ตัดคำมาให้แล้ว โดยมีวรรคคั่นระหว่างคำ
  #คืน ลิสต์ผลลัพธ์ที่เก็บรหัสอาหาร food_id ที่มีชื่ออาหารตรงกับ food_name มากที่สุด รายละเอียดดังอธิบายไว้ข้างบน
  #"""
    max_similarity = 0
    match_foods = []

    for i in range(len(nutrient)):
      result = compute_similarity(food_name,nutrient[i][1])
      if result <= 0.5:
        continue
      if result >= max_similarity:
        if result == max_similarity:
          match_foods.append(nutrient[i][0])
        else:
          max_similarity = result
          match_foods = [nutrient[i][0]]
    
    return sorted(match_foods)

# ---------------------------------------------------
def get_nutrient(nutrient,food_name):
  # """
  # รับ nutrient เก็บตารางข้อมูลโภชนาการ ในรูปแบบของลิสต์
  # รับ food_name เป็นสตริงชื่ออาหาร
  # คืน ลิสต์ผลลัพธ์ที่เก็บข้อมูลพลังงานและสารอาหาร รายละเอียดดังอธิบายไว้ข้างบน
  # """
  
  similar_food = match_foods(nutrient,food_name)
  if similar_food == []:
    return []
  result = [0,0,0,0,0,0]
  count = [0,0,0,0,0,0]

  for i in nutrient:
    if i[0] in similar_food:
      for j in range(6):
        if i[j+2] != 'NA':
          result[j] += i[j+2]
          count[j] += 1
  
  for i in range(6):
    if count[i] == 0:
      result[i] = 'NA'
    else:
      result[i] /= count[i]
  
  return result

# ---------------------------------------------------
def summarize_daily_intake(nutrient, intakes):
  # """
  # รับ nutrient เก็บตารางข้อมูลโภชนาการ ในรูปแบบของลิสต์ที่อธิบายข้างต้น
  # รับ intakes เก็บรายการการรับประทานอาหารของผู้ใช้ ในรูปแบบของลิสต์ที่อธิบายข้างต้น
  # คืน ลิสต์ผลลัพธ์ที่เก็บข้อมูลสรุปโภชนาการสารอาหารที่ได้รับในแต่ละวัน รายละเอียดตามที่อธิบายข้างบน
  # """
  
  result = [] # ['XX/XX/XXXX', [10,2] [123,1] [23,2] [1,3] [1320,1] [2,0] True]
  for i in intakes:
    food_nutrient = get_nutrient(nutrient,i[1])
    for j in result:
      if j[0] == i[0]:
        # Not Found
        if food_nutrient == []:
          j[7] = False
          break

        # Found
        for k in range(6):
          if food_nutrient[k] != 'NA':
            j[k+1][0] += food_nutrient[k]
            j[k+1][1] += 1
        break
    else:
      #* Add New Date
      # Not Found
      new_list = [i[0]]
      if food_nutrient == []:
        for j in range(6):
          new_list.append([0,0])
        new_list.append(False)
        result.append(new_list)
        continue

      # Found
      for j in range(6):
        if food_nutrient[j] == 'NA':
          new_list.append([0,0])
        else:
          new_list.append([food_nutrient[j],1])
      new_list.append(True)
      result.append(new_list)
  
  for i in result:
    for j in range(6):
      if i[j+1][0] == 0 and i[j+1][1] == 0:
        i[j+1] = 'NA'
      else:
        i[j+1] = i[j+1][0]
  return sorted(result,reverse=True)
  
# ---------------------------------------------------
def main():

  nutrient = [['R010007', 'ลาบ หมู', 267, 17, 23, 12, 2, 1470],
              ['R010014', 'ส้มตำ ไทย', 143, 143, 31, 5, 27, 1064],
              ['R010005', 'ก๋วยเตี๋ยว ผัดไทย ใส่ ไข่', 447, 49, 21, 18, 'NA', 1139],
              ['P010019', 'ขนมจีน ซาวน้ำ', 437, 62, 9, 17, 'NA', 810],
              ['P010021', 'ขนมจีน น้ำยา', 348, 41, 14, 14, 11, 1210],
              ['P010023', 'ขนมจีน น้ำพริก', 497, 75, 11, 17, 'NA', 'NA'], 
              ['P010041', 'ข้าว หมก ไก่', 481, 74, 19, 12, 'NA', 900],
              ['P020008', 'ข้าว ราด กะเพรา ไก่', 458, 60, 20, 15, 'NA', 1200],
              ['P010049', 'ข้าว ไข่ พะโล้', 464, 55, 20, 18, 'NA', 946],
              ['P010025', 'ข้าว ไก่ ผัด กะเพรา', 432, 54, 20, 15, 'NA', 'NA'],
              ['F010003', 'กล้วย ไข่', 62, 14, 0, 0, 7, 4],
              ['D010032', 'บัวลอย เผือก', 336, 62, 2, 9, 'NA', 'NA'],
              ['D010033', 'ลำใย เผือก', 'NA', 'NA', 'NA', 'NA', 'NA', 'NA']]
              
  intakes = [['2022/01/15', 'ลาบ หมู'],
             ['2022/01/15', 'ส้มตำ ไทย'],
             ['2022/01/18', 'กาแฟ เย็น'], 
             ['2022/01/14', 'แซนวิซ'],
             ['2022/01/19', 'ซาวน้ำ'],
             ['2022/01/15', 'ขนมจีน น้ำยา'],
             ['2022/01/16', 'ขนมจีน น้ำพริก'],
             ['2022/01/16', 'ส้มตำ ไทย'],
             ['2022/01/16', 'สลัด ทูน่า'],
             ['2022/01/18', 'ข้าว ไก่ ผัด กะเพรา'],
             ['2022/01/18', 'ส้มตำ ไทย'],
             ['2022/01/18', 'แตงโม'],
             ['2022/01/14', 'ส้มตำ ไทย'],
             ['2022/01/14', 'ลาบ หมู'],
             ['2022/01/19', 'บัวลอย']]

  # print(compute_similarity('ข้าว กะเพรา ไก่', 'ข้าว ไก่ ผัด กะเพรา'))
  # print(match_foods(nutrient, 'ข้าว กะเพรา ไก่'))
  # print(match_foods(nutrient, 'ห่อ หมก'))
  # print(get_nutrient(nutrient,'ห่อ หมก'))
  # print(get_nutrient(nutrient,'บัวลอย เผือก'))
  # print(get_nutrient(nutrient,'ข้าว กะเพรา ไก่'))
  # print(get_nutrient(nutrient,'ลำใย เผือก'))
  # print(summarize_daily_intake(nutrient, intakes))
  # intake_summary = summarize_daily_intake(nutrient, intakes)
  # for i in intake_summary:
  #   print(i)

main()