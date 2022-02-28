# ให้เขียนโปรแกรมในเซลล์นี้เท่านั้น ห้ามลบ/แก้ไข ข้อความในบรรทัดแรกนี้ 

import random
import string

def get_word():
    # สามารถเพิ่มคำใน words ได้
    words = ["HAPPY", "IMAGE", "TOURS", "FLOOD", "BLOCK", 
             "STORE", "AMONG", "TWEET", "OFTEN", "STILL",
             "STYLE", "LIGHT", "MIGHT", "WOULD", "SEVEN"]
    return random.choice(words).upper()

def get_five_letter_word():
    # คืนค่าเป็นคำที่มีความยาว = 5
    print('  Guess a five-letter word >> ', end='')
    guess = input()
    while len(guess) != 5:
        print('  Please enter a five-letter word >> ', end='')
        guess = input()
    return guess.upper()
            
def show_game_status(correct, wrong, not_used):
    correct = color_text(correct, 'green')
    wrong = color_text(wrong, 'yellow')
    print('  Correct letters - [{}]'.format(correct))
    print('  Wrong position - [{}]'.format(wrong))
    print('  Letters not used - [{}]'.format(not_used))

def replace_letter(original, old_letter, new_letter):
    # คืนค่าเป็นสตริงที่เปลี่ยน อักขระใน original จาก old_letter ไปเป็น new_letter
    # original เป็นสตริงที่ไม่มีตัวอักขระซ้ำกันแน่ ๆ
    if old_letter in original:
        k = original.find(old_letter)
        original = original[:k] + new_letter + original[k+1:]
    return original    

def mark_used_letters(letters, letters_to_remove):
    # เปลี่ยนทุกอักขระใน letters ที่อยู่ใน letters_to_remove ให้เป็น '-'
    for ch in letters_to_remove:
        # เปลี่ยนอักขระ ch ใน letters ให้เป็น '-'
        letters = replace_letter(letters, ch, '-')
    return letters

#------------------------------------------------------------------------
# เพิ่มรายละเอียดใน function ข้างล่างนี้
#------------------------------------------------------------------------
def position_in_word(ch, word):
    # คืนตำแหน่งแรกที่พบ ch ใน word โดยไล่จากซ้ายไปขวา ถ้าไม่มี ch ใน word คืน  -1
    #   ch มีความยาวเป็น 1 อักขระ
    #   word จะมีความยาวเป็น 5 อักขระเสมอ
    # ห้ามใช้ str.find(), str.index() แต่ให้เขียนเองให้ทำงานเหมือนกัน
    # ตัวอย่าง
    # position_in_word('A', 'ABCAB') คืนค่า 0
    # position_in_word('B', 'ABCAB') คืนค่า 1
    # position_in_word('C', 'ABCAB') คืนค่า 2
    # position_in_word('D', 'ABCAB') คืนค่า -1

    position = -1

    if word[0] == ch:
        position = 0
    elif word[1] == ch:
        position = 1
    elif word[2] == ch:
        position = 2
    elif word[3] == ch:
        position = 3
    elif word[4] == ch:
        position = 4
    return position

def check_correct_position(puzzle_word, guess_word):
    # ตรวจสอบว่าในแต่ละตำแหน่งของ guess_word ตรงกับ puzzle_word หรือไม่
    # puzzle_word และ guess_word มี 5 ตัวอักขระแน่ๆ โดยในการตรวจสอบก็จะขีดตัวที่มีตำแหน่งตรงกันออกไปทีละตัว
    #   ทั้งที่ puzzle_word และ guess_word เพื่อไม่ไปตรวจซ้ำซ้อนภายหลัง
    # คืนค่าเป็น new_guess_word, correct, new_puzzle_word
    #   new_guess_word ตัดตัวที่ตรงตำแหน่งออก
    #   correct เป็นสตริง ที่อยู่ในรูปแบบ '?????' โดยที่ถ้าตำแหน่งไหนที่อักขระใน puzzle_word เหมือนกับ guess_word
    #           ก็ให้เปลี่ยน ? ตรงตำแหน่งนั้นให้เป็น ตัวอักขระ
    #   new_puzzle_word เป็นเหมือน puzzle_word แต่เปลี่ยนตำแหน่งที่ตำแหน่ง guess_word ตรงกันเป็น '-' 
    #     เพื่อจะได้ไม่เอาไปตรวจซ้ำ (ซึ่งก็คือ puzzle_word ที่ขีดตัวที่ตรงตำแหน่งทิ้ง)
    # ตัวอย่าง
    # check_correct_position('FLOOD', 'FXXXX') คืนค่า '-XXXX', 'F????', '-LOOD'
    # check_correct_position('FLOOD', 'FLXXX') คืนค่า '--XXX', 'FL???', '--OOD'
    # check_correct_position('FLOOD', 'FXOXX') คืนค่า '-X-XX', 'F?O??', '-L-OD'
    # check_correct_position('FLOOD', 'FXXOX') คืนค่า '-XX-X', 'F??O?', '-LO-D'
    # check_correct_position('FLOOD', 'FXOOX') คืนค่า '-X--X', 'F?OO?', '-L--D'
    # check_correct_position('FLOOD', 'FXOOD') คืนค่า '-X---', 'F?OOD', '-L---'
    # check_correct_position('FLOOD', 'FLOOD') คืนค่า '-----', 'FLOOD', '-----'

    new_guess_word = ''
    correct = ''
    new_puzzle_word = ''

    if (puzzle_word[0] == guess_word[0]):
        new_guess_word[0] = "-"
        correct += guess_word[0]
        new_puzzle_word[0] = "-"
    else:
        new_guess_word[0] = "-"
        correct += guess_word[0]
        new_puzzle_word[0] = "-"

    return new_guess_word, correct, new_puzzle_word

def check_wrong_position(puzzle_word, guess_word):
    # ตรวจสอบว่ามีอักขระใดใน guess_word ว่ามีใน puzzle_word ในตำแหน่งอื่นๆ ที่ไม่ตรงกันหรือไม่
    # โดยตรวจไปทีละตัวแล้วมีการขีดอักขระที่พบใน puzzle_word ออก เพื่อไม่ไปนับซ้ำอีกเมื่อตรวจตัวต่อไป
    #
    # puzzle_word และ guess_word มี 5 ตัวอักขระแน่ๆ
    # puzzle_word และ guess_word เป็นผลลัพธ์ที่ได้มาจาก check_correct_position ดังนั้น
    #   จะไม่มีอักขระที่เหมือนกันในตำแหน่งเดียวกันแน่ๆ
    # คืนค่าเป็น สตริงในรูปแบบ '*****' โดยแทนที่ '*' ด้วยีตัวอักขระของ guess_word ที่พบใน puzzle_word
    # ตัวอย่าง
    # check_wrong_position('FLOOD', 'DXXXX') คื่นค่า 'D****'
    # check_wrong_position('-LOOD', '-XXXX') คืนค่า '*****'
    # check_wrong_position('-LOOD', '-XDXX') คืนค่า '**D**'
    # check_wrong_position('-LOOD', '-OXXX') คืนค่า '*O***' (ตัวอักขระ O ใน puzzle_word > ใน guess_word)
    # check_wrong_position('-LOOD', '-XXXO') คืนค่า '****O'
    # check_wrong_position('-LOOD', '-OLXO') คืนค่า '*OL*O'
    # check_wrong_position('FLOOD', 'LFXXX') คื่นค่า 'LF***'
    # check_wrong_position('FLOOD', 'OOSTW') คื่นค่า 'OO***' (ตัวอักขระ O มีจำนวน > 1)
    # check_wrong_position('FLOOD', 'XXXXO') คื่นค่า '****O'
    # check_wrong_position('FLOOD', 'OODLF') คื่นค่า 'OODLF' 
    # check_wrong_position('FLOOD', 'OOLDL') คื่นค่า 'OOLD*' (ตัวอักขระ L ใน puzzle_word < ใน guess_word)
    # check_wrong_position('FLOOD', 'OFTEN') คื่นค่า 'OF***'

    used = [False,False,False,False,False] # DP

    res = position_in_word(guess_word[0],puzzle_word) # 4 !!!
    if res != 1 and used[res] == False:
        # Action += ...
        used[res] = True
    else:
        pass

    wrong_position = ''

    return wrong_position

def replace_kth_letter_in_str(original_str, k, ch):
    # คืนค่าเป็นสตริงใหม่ที่เปลี่ยนตัวที่ k ให้เป็น ch
    # หมายเหตุ ให้เขียนเองโดยใช้ string slicing ห้ามใช้คำสั่งจาก library อื่นๆ เช่น  str.replace()
    # ตัวอย่าง
    #   replace_kth_letter_in_str('ABCDE', 0, '-') คืนค่า '-BCDE'
    #   replace_kth_letter_in_str('ABCDE', 1, '-') คืนค่า 'A-CDE'
    #   replace_kth_letter_in_str('ABCDE', 2, '-') คืนค่า 'AB-DE'
    #   replace_kth_letter_in_str('ABCDE', 3, '-') คืนค่า 'ABC-E'
    #   replace_kth_letter_in_str('ABCDE', 4, '-') คืนค่า 'ABCD-'
    return ''

def color_text(text, color):
    # รหัสสีที่ใช้แสดง ห้ามเปลี่ยน
    white_on_green = '\033[37;42m'
    white_on_yellow = '\033[34;43m'
    normal = '\033[0;0m'
    # text มี 5 ตัวอักษรแน่ๆ 
    # color เป็นสตริง 
    #   ถ้า color เป็น 'green' ก็ให้แสดงอักขระภาษาอังกฤษใน text ที่มีพื้นหลังเป็นสีเขียว (ใช้ white_on_green)
    #   ถ้า color เป็น 'yellow' ก็ให้แสดงอักขระภาษาอังกฤษใน text ที่มีพื้นหลังเป็นสีเหลือง (ใช้ white_on_yellow)
    # ใส่สีให้เแพาะอักขระ 'A' ถึง 'Z' เท่านั้น โดยเอารหัสสีที่ให้มา มาเติมข้างหน้าสิ่งที่ต้องการเปลี่ยนสี แล้ว เอารหัส normal 
    #   มาต่อข้างหลังตัว เพื่อเปลี่ยนสีให้กลับมาเป็นปกติ
    # ลองเอา code ตัวอย่างไป run ดู แล้วมาประยุกต์ใช้ในการเขียนฟังก์ชั่นนี้
    # ch1 = '1'
    # ch2 = white_on_green + '2' + normal
    # ch3 = white_on_yellow + '3' + normal
    # ch4 = '4'
    # ch5 = white_on_yellow + '5' + normal
    # print(ch1 + ch2 + ch3 + ch4 + ch5)

    # ถ้าไม่ได้ทำอะไร ก็จะคืน text ตัวเดิมเพื่อให้โปรแกรมทั้งหมดยังทำงานได้
    # ในการเขียนฟังก์ชั่นนี้ให้เติมรหัสสีและตัวอักษรหรือข้อความที่จะแสดง
    # แล้วเก็บลงในตัวแปร colored_text เมื่อทำครบถ้วนให้ return colored_text แทน

    # ตัวอย่าง
    # print(color_text('????D', 'green')) จะแสดงตัวอักขระ 'D' ที่มีพื้นหลังเป็นสีเขียว
    # print(color_text('OO***', 'yellow')) จะแสดงตัวอักษร 'O' ที่มีพื้นหลังเป็นสีเหลืองทั้งสองตัว
    # print(color_text('S?T??', 'green')) จะแสดงตัวอักษร 'S' และ 'T' ที่มีพื้นหลังเป็นสีเขียว
    # print(color_text('H***T', 'yellow')) จะแสดงตัวอักษร 'H' และ 'T' ที่มีพื้นหลังเป็นสีเหลืองทั้งสองตัว

    colored_text = text

    return colored_text
#------------------------------------------------------------------------
# สิ้นสุดส่วนที่นิสิตต้องทำ
#------------------------------------------------------------------------

def main():
    # ห้ามแก้ไขหรือเพิ่มเติม code ใน main()
    win = False
    puzzle_word = get_word()

    print("Do you want to show the puzzle word? [enter y or n]")
    show_puzzle = (input().upper() == 'Y')
    if show_puzzle:
        print('Puzzle word:', puzzle_word)

    correct_letters = '?????' 
    letters_wrong_position = '*****'
    letters_never_used = string.ascii_uppercase
    show_game_status(correct_letters, letters_wrong_position, letters_never_used)

    MAX_TRIES = 6
    for i in range(MAX_TRIES):
        print('-'*30)
        print('Try #', i+1)
        guess_word = get_five_letter_word()
        
        new_guess_word, correct_letters, new_puzzle_word = check_correct_position(puzzle_word, guess_word)
        letters_wrong_position = check_wrong_position(new_puzzle_word, new_guess_word)
        letters_never_used = mark_used_letters(letters_never_used, guess_word)
        
        show_game_status(correct_letters, letters_wrong_position, letters_never_used)
        if guess_word == puzzle_word:
            win = True
            break
        
    if win:
        print('You got it in {}/{}'.format(i+1, MAX_TRIES))
    else:
        print('You cannot solve this puzzle after', MAX_TRIES, 'times.')

main()
