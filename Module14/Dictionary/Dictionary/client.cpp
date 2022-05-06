#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <unordered_map>
#include "HashedDictionary.h"

using namespace std;

/*
template < typename KeyType, typename ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& key) const
{
    // We are creating a hash function type called hashFunction that hashes
    // a search key. First we create an unordered_map object for our KeyType
    // and ItemType.
    std::tr1::unordered_map<KeyType, ItemType> mapper;
    // Then we invoke the method hash_function to return the hash function
    // for the KeyType and assign it to 'hashFunction'.
    typename std::tr1::unordered_map<KeyType, ItemType>::
        hasher hashFunction = mapper.hash_function();
    // Need static_cast because hashFunction returns an unsigned long.
    return static_cast <int>(hashFunction(searchKey) % hashTableSize);
} // end getHashIndex
*/

struct FamousPerson {
    string id;
    char taxStatus;
    string lastname;
    string firstname;
    int age;
    string street;
    string zip;
};

void readOnePerson(istream& infile, FamousPerson& readMe);


// the insertion operator overload is just here so that the HashedDictionary
// display function can use it to print FamousPerson objects.
ostream& operator<<(ostream& out, const FamousPerson& printMe);


int main() {
    {
        HashedDictionary<string, FamousPerson> h(1000);
        cout << "should be empty:" << h.isEmpty() << " size:"<< h.getNumberOfItems() << endl;

        FamousPerson tempPerson;
        ifstream infile("famous.txt");
        assert(infile);

        readOnePerson(infile, tempPerson);
        while (infile) {
            h.add(tempPerson.lastname, tempPerson);
            readOnePerson(infile, tempPerson);
        }
        cout << "should NOT be empty:" << h.isEmpty() << " size:" << h.getNumberOfItems() << endl;

        h.display();
        h.clear();
        cout << "should be empty:" << h.isEmpty() << " size:" << h.getNumberOfItems() << endl;
    }
}






ostream& operator<<(ostream& out, const FamousPerson& printMe) {
    out << printMe.id << " ";
    out << printMe.taxStatus << " ";
    out << printMe.lastname << " ";
    out << printMe.firstname << " ";
    out << printMe.age << " ";
    out << printMe.street << " ";
    out << printMe.zip << endl;
    return out;
}






void readOnePerson(istream& infile, FamousPerson& readMe) {
    infile >> readMe.id;
    infile >> readMe.taxStatus;
    infile >> readMe.lastname;
    infile >> readMe.firstname;
    infile >> readMe.age;
    infile >> readMe.street;
    infile >> readMe.zip;
}


/*
436 s hxbfvx ppy 64 9th 94876
1390 m hvsilm jpgrxjnbzs 3 2nd 94671
1520 m nbedyvhdzlf erxwdfbju 18 7th 94639
6836 m jhi gckn 2 6th 94629
427 m ngn ubikzfeuxa 84 8th 94916
5668 m qswhg nxubmv 47 1st 94322
4642 s gyudjxbzlloz ey 3 4th 94707
1985 h e kela 86 9th 94656
2807 h cl aqrrfn 33 6th 94003
2767 m e lyqegyfqd 77 4th 94694
7116 m cl hmd 1 2nd 94273
33 m chomsky noam 34 3rd 94116

3711 s kskjba agdwemv 16 2nd 94290
6538 s f mnt 16 8th 94908
9400 m vivqyg ya 6 4th 94029
8107 h kxngnf bpixpfosjpip 66 2nd 94328
2347 m mmzfyuejhtr cgspnu 65 2nd 94610
9940 s lfzhkt ghcpkjfob 81 7th 94258
1381 m uggdvzg z 66 6th 94283
7757 s f b 94 3th 94380
4828 m edkzguxnin g 90 4th 94787
1414 h sowc r 63 9th 94038
8841 s f h 67 3th 94014

7125 h g jpeplyufj 3 4th 94207
83 m ikmwwzobhue dfhrvfywb 24 8th 94580
815 m inopfwc hawdhdywkohz 11 8th 94680
9677 h rkhgdptxlc dgql 1 2nd 94696
3201 s vtx svrhyndtteer 84 9th 94923
325 m mngzumawkyiu vkxib 37 8th 94879
1385 s pon dtwpl 5 7th 94797
6367 m g vpilgv 89 5th 94117
1161 s g xu 93 8th 94491
5581 h hbf tudv 26 9th 94041
7736 h tcbqhesjt m 72 8th 94162
7864 h g i 45 1st 94825
7419 h oxzbuxl bohbodpa 68 2nd 94352
3940 m plmo gm 46 3th 94858
9881 s nz kxrlozr 49 1st 94954

7409 s gdhy lx 88 1st 94916
5929 s zkcuqli hmfdjhtjui 18 5th 94113
9818 h swfq ezzlksnyjbtd 78 1st 94537
6058 h cqejdqrkpsxr qxlifzyacr 91 4th 94796
6606 s iwyipzwmh fad 92 4th 94833
1538 s h uceroxtao 90 3th 94194
7140 m h rbtsd 28 9th 94177
2480 m pahkgkhgbff lndwjm 90 3th 94849
5559 h rllitw lweweuen 8 6th 94567
7486 s ifaphamkj zf 32 9th 94408
5592 h hol a 61 2nd 94782
4660 h hbkdhtpfqy idxpdpax 97 3th 94097

7686 m okq avwdpv 45 1st 94744
1240 m aw gqtmcjmza 1 1st 94679
1455 s gnksadjzbo o 43 4th 94824
2045 m nhcahg opymjjrv 42 9th 94473
6215 m cwu s 78 2nd 94126
7181 m rzdfstfrynu ipufnkcsr 87 8th 94186
2508 m hrnue xhmrxwrhji 67 6th 94323
8010 s kjbteq ovixpjcxjvpp 37 1st 94679
593 h cughienxi zdqxyk 34 5th 94990
3974 h cttin ybpwkhvdjj 51 5th 94557
876 m vxgedxdl w 40 6th 94171
9116 s tagldxdl rfz 55 4th 94101
8766 h i kqgkhxr 17 8th 94700
27 m squirrel rocketJ 17 1st 94122
12 m dylan bob 37 3rd 94311

1012 h ymeotklkjbe tmzagsacnq 69 8th 94595
3278 h sdihqtxxaauw ejxv 75 3th 94985
4679 s zbfkainsok ygicqjtbp 89 3th 94218
2507 s looysnsh dmansy 73 6th 94746
1355 h okvslvca fggq 38 9th 94646
3722 h gkfogtls gc 87 5th 94978
7662 h jsz cfwygs 55 8th 94808
5210 s pvtcrehon gk 48 2nd 94565
9624 s jfu ehutb 6 4th 94590
334 h rpaa whlmlbgdlqx 0 5th 94189
5358 s eezhgfysae mtmmdjrmwf 10 6th 94154
8459 m j ufwisj 64 6th 94178
4479 h bhqv b 18 2nd 94709

6105 h oqskibkyiqv qbe 39 7th 94946
8437 h swgadyfqhybn cwwxeon 63 2nd 94349
2493 s cgevkar atggptrbpex 31 2nd 94388
8974 s afqvrjxafl nib 1 6th 94616
80 s ay rltkbmftzd 58 4th 94551
1176 h adullftayp atuozai 19 9th 94283
8308 m uvh avljxqymxung 59 4th 94624
4773 s qbzno yynoz 7 7th 94079
1507 h k qeljdai 61 8th 94299

6359 h zkhrz muhtrjymqgi 4 5th 94717
8496 m px kacdfacojdda 99 7th 94996
6252 m idfzg suwmoqo 72 5th 94119
3168 h whyfa xv 26 1st 94751
9410 m l kqindymu 63 9th 94040
3747 h veampiplsub ysztzqtud 9 6th 94707
4892 s uzfkxcryyues ymkyofcirdn 65 5th 94745
5966 m yvoecfohchk kwanusqsuiec 6 1st 94804
74 m cgmt wonga 11 6th 94747
5442 m kopar an 29 6th 94495
8348 s ovdopaat vbkizt 51 9th 94975
9584 h gvsjbjpitg snuarkt 19 8th 94151
1005 m l hbavgpwotjof 86 4th 94885
2349 m l ptfd 38 3th 94164
5266 h mdkxxk vajoz 91 9th 94427

6666 m vd znmoat 95 5th 94112
167 s ygfpnfu rzdvaqwm 3 2nd 94851
7030 h bjsretsaotbq boyr 86 5th 94518
1188 m tdxj gne 77 9th 94674
5535 s yomsr req 42 3th 94102
4059 h ct jo 44 1st 94030
6984 s m sb 2 1st 94766
2460 h m uqsurwupvdlv 52 3th 94233
5551 s cohfsniftd k 71 3th 94029

1983 m ikswvoeqxhbs ejjkuehbyh 24 2nd 94200
484 h n vuyeuhwgmif 62 5th 94112
388 s n frqxphuw 50 4th 94676
7458 m iymzholenmb amafv 46 2nd 94147
5377 m pz kojvq 60 7th 94541
2483 m yhk nphykmkiolrm 2 3th 94240
2232 m cpnpek kaxvip 23 8th 94967
4257 s mcx azldcjwlnxes 41 1st 94835
2195 h jlrlzqcsjwvl bvrqgh 36 7th 94059
3947 m jfhjqzu rtncorkjsfxu 13 1st 94344
8444 m tps f 83 7th 94995

4135 h qnacnhotuc uredazpcp 73 3th 94476
7427 h o jbrk 26 1st 94523
8984 m xnsruilm evpctfrldoeg 85 5th 94566
9101 m tomity aqnbz 84 4th 94406
2220 h ague tlvvzqwcekz 58 8th 94709
3959 s tzkng ptovheojcz 54 9th 94758
5400 h hos dxwfbdmivtmm 27 5th 94092
292 h o ezugfwvwewh 71 6th 94462
6035 s dvdcdutx pk 81 2nd 94908
593 m rzokkhb n 74 3th 94269
2975 h ykbciucpv ox 54 7th 94869

6938 m gbfwzak m 40 1st 94958
7031 s toxwuqfwnwnv dscp 48 7th 94041
8566 h p cwqukhmsoe 6 1st 94362
7047 s p zlcf 63 7th 94460
2421 m thktfdhqxxsr ngpyhxarucyw 33 7th 94620
9110 s p annogvrcs 45 5th 94477
7067 h abkuoirajcwc tw 34 8th 94282
5350 m cspbgnocgqj whyk 92 7th 94777
1055 s veqfq fobuns 37 8th 94476
9130 h p acrxfiybyecf 32 4th 94779
3202 s p nziudfoceyxo 44 5th 94354

2025 h jyjimp bkdevpvo 32 2nd 94908
2043 s q kvpl 75 9th 94560
4369 h poxfmdqwpa pvzbfw 76 6th 94689
337 m q mpnxzl 94 1st 94269
3160 s q ghnopjtechtf 70 8th 94134
218 m vuqfkisxixku azik 30 3th 94863
9476 s vyvlmtrolqp h 43 5th 94420
9468 m omctamjxz rpzgmdjujqd 4 9th 94359
3560 s hgdlt o 17 3th 94537
784 s ltncopwmvhdy nikaxodvj 98 9th 94172
2654 h xyldjb uxuveioazfik 96 7th 94113
917 m q iya 25 8th 94672
2814 s vzm xlkbnmi 76 3th 94864
4423 h gvvq rdylf 61 8th 94611
1414 s q dcffzq 37 1st 94066

5924 s vmi uyjakvn 13 4th 94333
4664 s mskxkl kwvxiegjzwdd 55 4th 94527
1362 h akmyv sfaugc 98 1st 94248
3988 s r qwghz 89 4th 94329
5046 h bpjqtnhkht f 6 2nd 94990
5595 m cy ssqr 13 5th 94296
4647 m kuzgdvhqow uxdcjziwdf 23 3th 94637
4057 h uwtwut cbkmv 17 6th 94625
9114 m cy dokoz 2 3th 94655
2357 m r ddshrhxi 52 5th 94018

4467 m lzhbn xjabcsowtoaq 24 6th 94377
5952 h vzgzcyt ax 36 6th 94067
6180 s dgraulfpfb shyduuptd 93 9th 94327
375 s cz cswk 32 4th 94522
2054 h vptnosuou le 21 5th 94514
5616 m vyvawbyv yewkeibswxa 8 6th 94249
7044 s cxxaixqmhb mbvdfrwou 65 2nd 94064
1056 s tq acfzykhxdmbf 93 4th 94777
2777 m igisl kmi 79 7th 94999
4454 h xbkxvpyg uerd 27 3th 94169
21 h oliver mary 47 4th 94114

7887 m upwtztcgm hlagmclv 6 7th 94050
5843 s t utvcqjvbmo 26 1st 94107
7136 h yeixsrsvodbr ouhbt 28 9th 94109
3695 s t waqtqmx 14 2nd 94858
4389 h apkyrtrlmlwh hvessa 76 6th 94799
9999 m kpmd wadpkc 89 5th 94673
5768 s lpbeoduwfs wbsxabjmxu 31 2nd 94420
8137 h t ynprgdihh 4 4th 94646
1608 h t avogmwf 92 3th 94195
9426 m vk bh 48 2nd 94016

2567 h vqjil ikypoadhtayq 67 7th 94855
8632 s vjrjgrarj wlbv 42 8th 94242
3296 s tkkrfe zofk 5 9th 94134
495 s gchasxe vuruhye 90 4th 94569
2895 h u gbypwmlys 94 8th 94808
6818 m gn uje 86 3th 94567
5246 h aporsmi h 47 1st 94656

9676 h v wrfegloxogrq 84 9th 94548
9084 h yrmbu ytzlwb 84 7th 94481
3424 s sbqgpdg wxsprg 57 4th 94642
2533 h pso ywoosujgofg 94 7th 94120
1269 s jwbazel sol 50 1st 94209
1608 m vtegwoi qn 79 9th 94078
5348 s vkxwwmsubs diwpuhkknq 66 4th 94957
3107 h wsaloxntbgb co 89 5th 94634
4950 m v vtiqlik 76 9th 94798
1540 h xahlvnmwr itjdtzgn 80 2nd 94139
6669 h mnmyk qu 6 7th 94497
8022 s jphgeqxapwu zcbxjircewef 97 9th 94447

2283 m gzhsi ivrjb 35 8th 94676
8198 m wgsk acrxh 88 1st 94635
694 s nofrxyhz ifhejkidda 87 1st 94322
8398 m w g 76 8th 94198
7064 s qolbwscu uey 55 2nd 94007
3486 s bzorof x 73 6th 94487
9852 h olykotjhoufz r 68 1st 94923
1198 m w sujrpje 21 8th 94731
7366 m qwo zdickkaavo 24 5th 94984

3814 m x h 6 3th 94007
6072 s x gaainrq 95 5th 94595
3425 m x pfyjywzhqaym 37 7th 94240
4693 h feiuth rayabwfe 22 6th 94014
3786 s x oacgmsylxwza 63 2nd 94199
1905 m mimgxixsgc qczfc 88 4th 94270
3459 s zcvmy xydyw 60 3th 94951
6431 s fibomatmqk gedyuet 68 5th 94233
3809 s x fli 32 8th 94807
7028 s gxltna xvbjwfhfop 98 3th 94727
589 m x abqo 18 9th 94037
7680 s eijdtyujaw xsmdioqi 17 3th 94239
6115 s xh tytzdvfw 44 6th 94040
6630 m dsdtvm acwaufku 54 5th 94204
4232 h x qcyancphcog 99 3th 94191

8364 s y urnna 14 6th 94198
2075 s lnzdszraphcp ivfjjss 55 4th 94708
5780 m vtryzxmlfpqt rfhvgl 49 9th 94538
1075 s wov twwvoibzn 74 2nd 94151
7440 h y pemzkqixgnr 37 7th 94746
3834 s y jmpsonwwgtb 27 7th 94921
3717 h alyudijvrx rzb 1 7th 94683
7208 m btcahjbsm mukqsor 52 8th 94651
348 m xefmxg qucqdbtzkcl 79 6th 94917
364 h ydnorn lfimwqhdackk 22 1st 94156
6338 m itdsopvh qqenycwhh 89 9th 94695
2046 s iji ufnhgsmwxwtl 77 4th 94327
7292 h y vujcj 12 6th 94984
4637 h y uupwjzck 50 2nd 94783
637 s lubmosrfft kkpffchhdj 28 2nd 94385
329 h kci iz 58 8th 94814
5455 m cpk my 80 8th 94345
643 m bll ddbu 78 5th 94219
41 m douglas frederick 66 6th 94666
36 m kropotkin peter 49 4th 94115

9173 s sat fasulnjk 77 7th 94358
3636 h z uccdxayrwab 31 8th 94774
3121 m z ls 14 2nd 94773
2576 h z z 57 6th 94511
1768 h z roqffcomprt 55 5th 94089
2276 h ukbtvebb mikzvqxqwk 94 1st 94021
8689 h gs yhahoriiwy 94 9th 94736
8821 h gkmuazxqwx qqww 55 4th 94311
7247 s uimtyj awuxnoe 57 6th 94384
1331 h igurntctma mxcimjp 30 7th 94295
3010 s z qjqdlszgwr 73 4th 94949
4447 h xj wqs 39 6th 94377
6647 h z ro 64 6th 94902

4290 m dxfw scesfnpsm 55 4th 94362
4998 m etoawrzgz ak 76 9th 94227
3898 h vhfzb mfn 34 5th 94463
1050 h anjwictdawr xkmu 39 6th 94757
2485 h jtnn kkvf 14 4th 94594
2597 m aixlgp zvsnwgmzezor 49 4th 94384
5356 h nyvqmahuvi bbou 27 9th 94864
6506 m ksdvejnvfsg ltbvisyesak 46 2nd 94108
9370 s ayhomm ejyytkej 49 4th 94458
5079 s ckvib sggwnidij 62 6th 94319
8230 h jmvaaqkbfvzr gapvtuxdhvg 24 4th 94602
37 m gandhi mohatmas 53 5th 95123

9079 h dwbcmbljbr alakfar 41 7th 94202
9570 m ymlokqjuxjz cgj 68 5th 94114
6429 s vnitamnrmw sddpdyijmi 37 5th 94778
238 s ftvg rlwatrbkfyfe 20 8th 94226
9366 h lqom prsd 73 2nd 94108
24 s ciywzcp ttye 93 3th 94697
29 m peobody mr 18 1st 94222

4429 m iegzefhcys mbqqembbtxhr 35 1st 94900
8909 h xcczpuk yizklma 26 3th 94128
2005 s crh ybttlb 43 4th 94543
6815 h kh hccsbg 0 4th 94990
8366 s jiajubppoewq hyc 91 7th 94303
8398 m rlmhwfzbmhtz ednhcwptw 61 6th 94587
5275 s ssheckru imiohtvyc 44 4th 94300
30 m longlastname longfirstname 11 1st 94313

3033 h dpdfzy nm 53 7th 94846
8498 h dnfwgnfpj qhji 90 3th 94536
6988 h xfu vplamkglpiac 40 5th 94053
6292 s hkzyixzcm plifmxnvutmp 55 4th 94373
7506 h ubtntxhsyz nhdzgnz 55 4th 94354
1321 m gw djdqxxpssqa 51 3th 94727
9459 s jqmwk kljefqyhak 40 1st 94631
8842 s hjfz hwvhhqdtubmn 40 1st 94156
4976 m vu rscwephluxpd 31 8th 94152
375 s mvczsiwzaarc lppq 37 8th 94167
2440 m kcjg ye 28 3th 94090
6847 s guupxrwfqqxi qdltscae 11 8th 94650
6560 h vzysay bicpnc 18 7th 94199
05 h harris emmylou 20 2nd 94222

6649 s rxbkniooej xz 24 8th 94905
9382 s suictyen hbgxoyp 22 3th 94792
8065 s wbw pwomnvss 90 4th 94466
5096 h pywsbpwga vz 5 3th 94795
5863 m nebwgul ptht 92 9th 94154
8803 s soyttmv jqdlldymfu 93 8th 94940
6917 s qmjkakyqmwl iwqi 81 9th 94698
9814 s kj lu 13 7th 94353
5179 s wilxlniwpwu kajwxlltg 49 8th 94502
8141 h artelggnkp nwyduwqtfmta 22 6th 94602
1137 m ufhqw vxbpy 99 4th 94803
5391 m fpxjjadnlmnr yoqooxncc 72 9th 94201
6844 m yesdyzbng opn 28 3th 94602
7822 s ntxovkbdp epq 41 7th 94688
9288 h yqkomqlha c 88 7th 94439
331 h cgvclzh ruxnloov 85 4th 94165
2134 m thlbrct rhga 97 4th 94597
1489 m vrxwbbeky mycc 60 7th 94517
6300 h mhkvif ymptywv 80 6th 94362

9254 s wclztmauxajs ch 63 4th 94975
1634 s qoea anrukcxgoqf 39 3th 94720
7696 s yocsadyruied qm 97 3th 94263
2506 s nqf vuxejxotute 59 7th 94226
592 m zfblydtr xgv 67 5th 94218

2117 s vqj o 6 6th 94909
4811 m fccpaqnz ujumlzcivj 23 1st 94307
1369 s watkfdrt ap 19 4th 94007
5457 m lxebpyt hcdl 24 9th 94221
2408 s jbqdufvyuks laxem 57 7th 94951
9863 s ylwekw qybmihl 92 4th 94406
6529 s vexuqojimkfq atokdb 13 4th 94697
3897 h wwdmuskchble dawfrycge 33 3th 94578

3006 s ekniieshpqzk lyfacnrnqt 74 7th 94626
1797 m hlgacygveexr qzsxxcumksao 42 7th 94640
9185 h snmtjchozy imcwltlel 17 1st 94635
2817 h zk avwnuja 5 7th 94105
643 m wtxrdonftxf cibvjaipc 78 9th 94301

5639 s cgb ijibc 34 9th 94708
5569 m qnh pwnqeb 96 5th 94055
4105 m lqgao dqollcmzfbtt 22 4th 94668
7385 h tmpbxwektj iqi 66 8th 94462
5316 m uxjoxw fbhmtchhehhb 83 6th 94358
9334 h mdyrifzemix t 66 5th 94429
1121 s kbdjck zq 87 9th 94276

3479 h xcdttflts jdqhqm 23 2nd 94057
4144 m iv jyuvmfntuw 31 5th 94036
3878 s fsvb igsj 51 1st 94617
3456 m hquwju poyp 31 7th 94250
7164 s gdzek xgt 67 3th 94798
7279 s vkifkqrniqa xrj 18 9th 94289
5910 m iubszh vlama 61 6th 94934
8325 s cxhjm yrkgebpnbd 49 8th 94055
1645 h hlcr onzo 41 4th 94891
2391 s iojaemyojmcu vbtqptsk 34 6th 94630

6311 m zn yclhgmrlrp 76 4th 94537
382 h jrihznk k 56 8th 94316
2067 m zn h 13 4th 94722
9199 h svhz yhfce 19 7th 94496
4168 h dza xgx 68 6th 94226
527 h wxpikwzp gkik 93 3th 94655

1308 s xv dmokosqdbody 1 6th 94331
5332 m oeunczrkqi lrjidgwjmstd 28 8th 94176
241 s scfljrerbapm pnhhzsutncgg 76 1st 94902
9178 s xwt rso 33 6th 94372
1290 h ftxj wv 57 4th 94189
9838 h mj xswuwlzjt 35 3th 94013
9815 h usvwy zfahelsud 25 7th 94588
2192 h byrhgon vvohyw 65 5th 94405
1883 m mwmzgff lfdxtqwjom 36 7th 94118

5513 s jfkrp zsuhgjsjxmmj 95 8th 94065
6807 h ggtfceqbof bk 31 5th 94027
9828 h od blvxjpe 2 3th 94165
7812 s pudxdgrkbl hkccvnshi 69 7th 94367
6189 s rxpkplifvw rmfddswrxle 70 7th 94596
7696 m unuaiej sb 54 8th 94731
7350 h zp talonmybcqrl 65 4th 94421
5964 m uyvoclqhrw yhhn 49 2nd 94842
6507 s dez xnbi 93 7th 94446
2063 m iadu kt 89 9th 94386
9395 h ylv cwzo 87 3th 94918
6953 s jxjrdjav cyykpi 49 3th 94109
28 h fenwich nell 13 1st 94221

3849 m njnimfgpiob aammk 73 5th 94951
9984 s jcpa s 67 6th 94363
3455 m dnbdku bta 47 4th 94546
6858 m leiowxfkcs rdxrmroprcuk 83 1st 94058
4320 m mgwszh wddwjwq 85 5th 94395
2183 s wslmfbcnsiev eshzzkvjdq 43 8th 94586
9933 s yqvdpotreyf dytbng 86 8th 94641
3301 m qgny herwvihuyi 58 7th 94730
1347 h zgkbmgfanb c 54 2nd 94400
4640 h jfdoyalo cdnqpg 7 5th 94320

6751 h oafhfaufye ef 17 1st 94531
3135 m cqkvmb qr 67 6th 94289
1927 h ibtdb a 82 2nd 94947
8364 h jrj kqeedv 85 6th 94057
7742 s lxoazdtv nrawbowhb 94 9th 94992
3908 s svl qnoshv 10 2nd 94542
4749 s okxydjpv s 61 4th 94873
5834 h qmpene wzwlsohmif 13 2nd 94912
5508 s tsmzsw bdj 74 3th 94004
1965 m nsh edlxlwt 21 6th 94718

9207 h rsvspnaqfnn qznyxsq 5 8th 94869
6942 m oggk exitis 95 9th 94861
7967 m jyfcdod f 54 5th 94651
3664 s lzhuu jt 55 8th 94426
4128 s qqyhmrtzane co 18 4th 94373
08 h warwick dione 26 2nd 94222

76 h avkkjyh piw 7 3th 94511
2162 m vwajufnfwjb nbpbfimpn 26 6th 94741
6189 s mo d 1 2nd 94830
1929 h qowltjgouf rx 55 5th 94212
9022 s eakxkoovygdw lymul 77 1st 94768
3353 h vuupxnby eqhi 36 9th 94549
6800 m xpuiwqnhmi hvwfyndnrb 65 3th 94865

4741 m urxobreefov nnlztw 52 5th 94722
8087 h streoreqce xyttki 11 9th 94177
5707 m ftifidlbmqt zdhdeidtosv 93 5th 94502
9737 m hkrddt elsfswaftc 43 3th 94470
1080 s lwmm txixdhnyipas 20 7th 94613
4540 m fjykfpbutfd dmctm 32 7th 94125
5232 m wtlzlryg kkguddcwwqf 64 7th 94044
1035 m kiwqpu yhyltdm 68 6th 94656
3246 s rxvrxgut euclkgzqj 95 4th 94351

4748 m olclqznbsm frzezlyntkla 39 1st 94011
9232 h xckvw odcusphevmuh 73 4th 94769
3027 h xyxyu tcrgvhy 98 4th 94453
8843 s gyiitwfjphvt qa 43 3th 94076
5905 s nxtbirp gmlfb 44 9th 94620
8274 h gbgtze cvsa 3 2nd 94351
7779 s kmid afx 97 7th 94321
3124 m lmimoqiiw pomg 52 3th 94602
619 s czlqjhknz yvmwyqq 66 4th 94103
588 s qhijfogeu hnfzeehpqb 77 5th 94715
8119 h axdejnmh vvvoln 75 2nd 94340
4280 s lckvkspjhbs bxvpjgqgw 17 1st 94998
1889 h ihqgdmor mbmn 84 5th 94913
48 m galileo galileli 58 5th 95113

6889 s tyyiapnz zakmppzt 75 8th 94012
282 h zhkqmac wsryy 28 6th 94894
3804 h cnnvh ofsxvp 65 3th 94640
4873 s mbhg yaremnpyn 23 4th 94663
1353 s jljwm pviwzzbhq 67 3th 94906
8113 s aiimkh dhqjffqk 90 2nd 94562
8288 m wcnagzrk ycuday 66 9th 94641
7760 s lwyacb mgnbwqx 22 3th 94764
4458 h rvd twfqo 23 6th 94803
8433 m usdogdwskp obhgebmydgi 81 7th 94684
5603 m zw ijfouqd 88 8th 94741
2857 m zgi ohsvk 54 9th 94063
4746 s lgaofvath c 32 5th 94080
1593 h cgm txi 29 4th 94084

8564 h kvtsozbck tmwygu 48 5th 94065
4274 m ekmktlfwany iez 88 5th 94128
157 h vyvnld wonydfvfsmdp 90 8th 94826
9875 m lhtczplj azwhssyfmszl 8 9th 94164
9162 m ocyen hw 31 4th 94477
5498 h zekxfetflk sui 82 8th 94931
7925 s idkxuf uloy 15 9th 94262
6512 h wzlcwx kqrzxugboj 70 7th 94150
8999 s hjr rgrierkxcx 15 2nd 94916
1673 s ms tznbuxjsagwp 85 7th 94434
7710 m vvnkbld lv 93 1st 94545
3453 m zx bbl 56 2nd 94458
22 m kotzwinkle william 44 4th 94433

8718 s ouu akjb 68 8th 94406
4581 h pptrxgu kuzphavyfllv 90 4th 94295
828 s lmep yrvnjdw 10 4th 94180
8410 h kpdm wcccijqsmo 72 6th 94002
9795 s tihginrzfqo hvelvl 66 9th 94248
3450 h vfm xqwgkf 98 4th 94017
3737 s ikijdyva fpvwowhl 49 1st 94326
6541 s ufeldpl gapetjeva 31 3th 94378
1312 s qf sp 47 5th 94571
4501 s jjbmwksuzcgk vlr 51 3th 94030
4595 s xaf eckgtgedt 61 2nd 94436

3440 h ogensp p 47 8th 94889
4597 h bgwsv ivv 1 5th 94754
7129 s eteytbc scwaho 31 1st 94388
4093 h pjfe ogmoevu 55 7th 94006
2157 m pgdisvyavaa fcdwybtl 68 7th 94047
2300 h qcrbbkdrk txmxisdw 34 9th 94535
9980 s bgnnvk gpj 18 7th 94669
1904 s elvlcotvkmn emgyyghugmk 99 7th 94411
1043 h wdghhoexghuv xsin 78 9th 94246
1752 s bi odzbxkpcylru 89 9th 94874

9548 m grtwmbjd acffgfcvzqq 4 7th 94531
2522 m lombjd oewou 40 1st 94948
8121 s joql dmm 48 3th 94484
1678 h hiewvfgejcu h 49 9th 94249
4696 m harzygukom jgmdantvczsd 87 4th 94365
3009 m efvjwltfab zidfvhjsk 83 7th 94584
7012 m dxzsfgimhbi ffupqymm 32 2nd 94390
3919 s oqphmf nnea 91 4th 94736
8285 s kcnenx zuualznl 7 4th 94883

8153 m dxv dzai 94 2nd 94176
4949 m hcwfoqbjxdx ykub 79 5th 94344
542 s wfrpradojq gvweuqmnjori 82 5th 94903
3602 m zvyyvjzice whardz 6 3th 94559
6671 s ocinuhkem efco 55 4th 94506
8013 m hnahzef wgzzsbvvpac 19 2nd 94782
7437 s lsogpumbje halcatvqp 85 4th 94349
8001 m op majis 58 6th 94442
3204 h sjsdpjlpdk pg 91 4th 94577

6412 h jsckfnomh p 30 6th 94349
3463 s bdrfvvwtaqil oedhhx 71 4th 94891
7464 h keihkmamlnu odw 37 4th 94961
8227 h bctbauwri ekoschv 20 7th 94724
7335 m jvmsv k 17 3th 94874
5728 h eudk ppru 1 1st 94519
7698 s vafcaddl bqtzxqzccbi 56 3th 94443
3422 h zndq vtugu 15 8th 94744
17 s chapman tracy 43 4th 94211

7414 h mgeqa hmepo 31 3th 94146
1832 s fukpydlgqb yjwwmjlsbe 83 1st 94462
246 m lqa gpwfjtq 53 2nd 94202
1856 m gpifvdrkaptl qanmywkczyq 0 7th 94006
4436 m yro fdvunqi 55 8th 94397
4942 m nyjgvfh kkmyrttrmqm 29 5th 94603
1916 m slcbex mupilcwbqnf 87 4th 94555
456 m uqwjyczgcnwp muv 25 3th 94158
3081 h wiqdaediz jlpevtoprx 77 9th 94136
9473 m gtjoh eiw 12 7th 94422
6389 h sgobwpk xximyplwszs 32 3th 94658
44 s parks rosa 72 7th 94777

7135 s czfszbo ydgenvcri 22 8th 94966
854 h qgusa oxzopbwqziht 11 4th 94558
1988 s ql e 30 5th 94711

187 h uupiavonr jopqqvyphg 45 5th 94627
7660 s wgjx snc 84 4th 94240
9857 m vxvlaqecb cewtuuntanu 83 5th 94268
5587 m ityhtwrq ukvvsjre 54 5th 94898
8582 h brunhlmsuyv cjr 53 9th 94258
586 m khdllgsuori ejkihf 83 9th 94126
7824 m yumcac izpobclijn 85 7th 94229
8397 h szl hgb 64 3th 94221

7038 s dvwq icwcvlodxrn 98 1st 94429
88 s hqibkcvoswid d 96 5th 94213
3725 m ixjm tuhbnhnwjh 23 1st 94686
787 s yzkf ix 58 5th 94471
7845 s iezgs jtxqndb 49 4th 94787
5393 h urfpnsgvc m 5 3th 94986
5701 s fb w 78 3th 94609
4701 h ivjqwzkp pvrafhimhf 10 6th 94455
45 m russell bertrand 55 5th 94113
32 m hanh thichNhat 26 2nd 94115

2960 m cxhea tymzehk 77 7th 94659
9571 m hnn ptvwamolg 36 1st 94784
2801 s iapqpaop vgiapoldzr 9 8th 94212
3535 m xignhapb gcdbjxoo 82 1st 94161
1042 s hvcsol mxgcd 82 5th 94709
4907 h bdyqge onbvcydpa 12 5th 94752

7468 h fjntbxbsor ormtxhwj 90 3th 94101
3719 h gjp r 9 4th 94239
4939 h knbcgtxmzsmf rzykumy 37 3th 94647
1102 h cwfghr kvtdggfmyadf 25 7th 94945
7074 m pwbip pwiaeyda 36 8th 94344
1737 s xcmihi kymdnnmvbn 42 1st 94515
1865 s vuioryril tt 2 3th 94167

2403 s iefwoelbi eoioxwdlehf 16 2nd 94752
7381 s rrvbejkb ivuhwjmdpbd 95 2nd 94237
8479 m yxck g 23 8th 94078
4499 m ox bnjdvn 79 5th 94702
9206 m paqyybdvmxso xllacj 38 6th 94473
4729 s wpb efpxy 72 1st 94433
7888 m cdxocjp zzxmhfjkl 92 6th 94086
4624 h wihwdhoaub pzt 58 2nd 94235
7237 h qyfc uovtpzfijxw 61 8th 94833
5658 h llifmtge gh 66 5th 94766
1981 m jlmpljxuw sonicd 64 5th 94068
1904 s jxg hqrbzjbhwcmr 51 2nd 94041

6730 m bomobtwufw ljbx 25 9th 94949
2626 s okfvoaltgk bjubpwyqnwax 68 8th 94652
2173 s jxh jjuvty 45 7th 94221
8096 m kmazromkeong cgs 41 3th 94296
6629 s ud id 15 6th 94007
9186 s sk mns 31 4th 94474
7896 s htuzhdlvoi syinwjr 94 3th 94092
6851 h wnpupw l 18 4th 94608

6206 h gmeukvudst jvbqqwmgluz 23 3th 94113
6647 h gdhncbnjnqj wpct 24 6th 94714
6476 h ywyyliycko lgokxpeqwxax 96 8th 94175
2072 s fzrobgzrex qzmdgzfqs 96 6th 94093
4197 h oz ia 78 1st 94015
8397 h hgwi c 51 8th 94185
439 s lqi vnz 85 5th 94385
4780 h zlyqogw avuvqub 28 6th 94666
4211 s zllru owzjwyb 96 5th 94310
47 m darwin charles 59 5th 95123

1915 h bv javcevh 89 9th 94657
3246 s nvrultfcg arpvalotmf 51 8th 94229
2200 h bsbq gkwbgmhi 29 7th 94040
6354 m aerycvrkx avzhlrqgptb 16 4th 94046
8873 m vctrpmk srx 16 5th 94227
9030 m fwljamzaqvgn j 31 5th 94370
4843 s gglog pbniyu 30 7th 94236
4239 h afsatrufarmu ueywo 2 3th 94419

4018 m uulo bqgciwb 45 3th 94873
5756 h xqzlhvwmiqnp yladmy 1 8th 94746
5375 h bdxlfe iujyxcyhqdyy 48 7th 94043
9963 h oknbjl ibgykukudll 26 8th 94559
686 h lvjwvtikvk bnlfnuard 68 5th 94757
3091 m qu uhxyh 31 6th 94104
3999 h fdnnlzal zb 7 8th 94876
9615 h neolq qjefsuwi 70 6th 94240
24 m heinlein robert 74 7th 94765
13 h baez joan 36 3rd 94311

3038 h kjzybqvx fsk 26 1st 94715
9741 h drfpx fova 41 4th 94423
1428 s jiorntpx oug 25 5th 94763
3508 h bik oakgjzm 35 2nd 94927
9480 h uxxgjlljxyn n 90 5th 94433
8446 s bx gamdbzrinf 76 8th 94864
8190 m vwsgyuepas kghd 76 8th 94216
6493 m ztlcta ibdczvtywwoh 67 4th 94914
9095 m aejp xmzxktzf 92 2nd 94555

4664 h kku ujdlsj 1 4th 94651
6976 h qweqkgoz myhotwbb 30 6th 94721
3579 s tsbflcpdak mxiakmelcc 77 7th 94658
1276 m jynp paeiwkubihfy 57 8th 94051
8797 m xrgxj xmnhrabnjlhi 46 4th 94721
6685 s yeiyfpsswm oauqihu 59 2nd 94602
7763 m trow hxxzciui 43 1st 94085
2348 s psvrs vulsxodfggf 59 6th 94273
4052 s njm nrnlmi 40 8th 94032

4200 m qry ggc 60 1st 94379
4701 s vugcjdanrf cuz 81 5th 94020
3145 s vmuzi daempq 33 3th 94259
5366 h fuoiwqzh mxyepimb 65 4th 94301
4790 h xax bynl 14 7th 94358
2217 s unhiwfx qle 12 5th 94021
1289 s uabbg jplanc 39 2nd 94644
4716 m yhwjdrtca hwedjtxvniqf 59 8th 94810
2825 m nfaait okrns 51 6th 94688
1651 h jqnn uzjmbtgfbldm 21 9th 94032
9959 s ghgzgjnajb wy 3 1st 94109
5751 h srbpverquswd y 42 4th 94087

6681 h qfxcm lt 52 8th 94203
8235 h wd rttjnbc 75 4th 94743
8722 h sqe seumiii 9 2nd 94740
39 m king martinLuther 52 5th 95112
02 m guthrie woody 23 2nd 94223

4895 h dknnqiaxmd ihpgqpo 12 8th 94125
1800 h ujvnvksmjqpi hyrritqa 14 6th 94181
3903 h cokrlrrya lmhogtvsx 80 7th 94654
8202 h qtt ttzs 33 3th 94257
1974 m uqzt rguznngjeksq 67 4th 94978
4985 h atrpmwud mkhtttzdk 83 1st 94718
2332 m emtxoc uhxodvtw 71 7th 94525

754 s bqcimb shrnxkizexu 38 3th 94444
5024 m xiuqm fs 75 9th 94051
4203 m iluibhgwq zmplaxmmjwxr 33 6th 94862
2203 h fo atnnzu 0 8th 94413
7913 m letmrgxbwgh szqgxaj 60 8th 94532
6366 m pjpsqkmku dvvaqnn 98 1st 94567
2559 h zlqwofvw gqkbq 44 7th 94021
4862 s heg pl 37 7th 94746

1135 h kol rtk 37 7th 94868
203 s tjwnlv cbtwjbymzxmy 7 8th 94095
4164 h twvdwny hocg 44 8th 94248
7290 m pcr laphihb 57 7th 94759
9825 m zjajql cruuffsc 41 8th 94757
1670 s ecwljc cvecbi 39 8th 94477
6491 s dnrmco us 58 1st 94126
3113 s czu emtowax 46 4th 94672
6118 h batmmqhmu bh 74 7th 94277
9144 s yajtxv vmsloirz 55 3th 94032

7709 h hj joozlwuzykgf 1 4th 94177
7982 h aaduv ibvkum 39 8th 94822
2607 h wh hbna 73 6th 94757
4210 m jc tysf 56 8th 94665
4088 s fzxttprnih iwshnbrm 68 7th 94378
6625 m mft nqr 35 3th 94355
511 m zupufetlvbmt apptynqewy 46 3th 94429
896 s jqmnofgqhxan ln 98 7th 94613
1481 h acdwffqabt efvmkrpg 97 6th 94084
2060 s jc fg 33 5th 94506
8880 s uo blyueai 45 6th 94582
4392 s qunvnlqafbim cvdhmf 68 1st 94684
4303 m hzdqvvhttgtt ltcttsvtf 42 2nd 94748
43 h mandela nelson 60 6th 96543
01 m motzart amadeous 25 2nd 94233

9985 s zovyxcbbc prfjmqnrpa 46 1st 94717
4693 m gjtx kniixaqyrt 12 7th 94186
4756 s yuuyyeqbur yh 49 6th 94856
6693 m wvwchyqkf lmgfm 74 3th 94500
5270 h lfuaurlszhl sl 46 2nd 94078
1897 m sjyzefn mburiwdgjn 82 6th 94032

6381 m pqyjoc yaexflby 31 3th 94056
5175 m yhqspe moesaetwb 3 3th 94385
830 h loxhwuyt bkfvviz 70 6th 94331
6528 m usyoaezbvef o 41 7th 94083
6170 h tngg n 54 6th 94045
7206 s lbrwbrbo vicjhiyjutaw 90 4th 94263
7431 m tiwyo kpzyw 39 6th 94597
9185 s dail cyatrkwry 36 3th 94750
389 h oqrslohxci hyb 70 7th 94227
2509 s jetzum jlnv 85 4th 94734
7697 m xthk wqsvdeh 45 5th 94284
3363 m hti mxkxcwaemfzh 90 2nd 94111
1894 m objbl efobnodzbdx 60 3th 94905
7283 h sx skudgssppi 11 4th 94779
5699 s irjkqdldu fnikgwd 48 4th 94704

5796 m xbdmlg noyyqbgrlyz 96 9th 94201
4551 s iyinlnsdae zj 86 1st 94730
3006 s zzcmp vlr 36 1st 94747
3364 h lxplzyihmkrp pkbpsqz 22 7th 94176
536 m wioa tyssdvqnejlm 96 2nd 94769
9217 h juwtx hjg 14 6th 94734
9843 s wpq bqu 67 9th 94787
7630 h kvavibupf hft 45 7th 94860
6456 s vqzvvpt tpzysfg 8 8th 94393
25 m asimov isaac 75 7th 94777

261 s jlvscrcyo bwh 2 4th 94936
7633 m sz ccrgk 90 7th 94275
7813 m xzivm bgnk 15 9th 94594
4722 h ghdeowesqm d 70 6th 94421
8920 m lyrtkjeqh tohkikfl 49 3th 94188
8578 m flm wqn 10 3th 94597
26 m moose bullwinkle 16 1st 94111
16 m mcdonald countryjoe 46 4th 94543

5855 h epvh b 44 6th 94138
5981 h eeijvk ugylhjv 72 3th 94711
9674 m pskwu cmua 99 4th 94411
2154 m efltbsn vxjrmwcwvl 60 9th 94018
4265 m ylbsageu rzucobqs 38 9th 94271
9992 h ho lkmvfslkl 54 8th 94936
2215 h vah me 74 9th 94840
6787 s rgijzsssbnef oxjmsscn 13 1st 94842
4711 h wmmlygnooy hlvbcrhi 83 5th 94258
20 s walker alice 37 3rd 94332
10 m franti michael 34 3rd 94112

8456 h qkegeb wepvlfxrz 70 6th 94678
1502 h svkjrp rxxgnrl 97 3th 94013
7050 s rbjf kkdwugpbblh 35 2nd 94037
3963 h xmizlihjaan arlhbjelml 23 1st 94475
4319 h wn erg 42 8th 94213
9004 m aedpxkhww tqlwwozfysrt 99 6th 94416
987 m zqnbftui mtqdufmmwagn 76 2nd 94129
3246 m dvcxpqxqwqg ysifqqabywzt 39 8th 94253
4473 h ueyhcw zrhkbq 62 4th 94239
3292 h lpyxevybj igo 3 7th 94495
8005 h ttulabsuzwe pu 32 3th 94275
963 s xscnpokusd lrmdrmrodu 40 9th 94558

8341 s lerhwah rdknyugn 94 1st 94922
8755 s xjyxxg tkhra 69 8th 94686
1299 m otts dblqyojqmy 74 6th 94465
2655 m fyowud rohgivgbeijw 36 6th 94687
2754 h zvawvyjymws vqchq 51 7th 94368
1981 h yeksf itzcv 28 9th 94037
3291 m iilstao funi 69 6th 94450
3022 h ulvmsobnfbf vb 62 6th 94774
5139 h kfcevkxbeuyn jeqzn 76 3th 94960
770 s ytdhxte a 79 8th 94866
6212 s antzft emppdtkjhany 85 2nd 94680
3834 h xsspfpgmawx wszilpakw 17 7th 94499
2830 h htn omyyvzfbqq 81 7th 94194
04 m lennon john 29 2nd 94221

1480 h lhpomclqhckq xiftcl 89 7th 94380
3748 m ssj fqyvop 80 7th 94287
8679 s ld yhfroioj 81 3th 94936
5325 h bks pfcxotdnwze 52 1st 94663
7592 s gqksma dcc 71 2nd 94755
961 s btlnff dbzfh 32 9th 94028
8836 s ybznnahv rxjoecempe 21 1st 94163
2301 h dwzbt tvrtabrftixl 99 8th 94527
3352 m azd cuksquczi 81 3th 94742
1412 h hr dwm 76 8th 94092
9856 s ocixx sgqf 91 1st 94733
5301 h vzqw ukdapyomedml 29 6th 94375
10 s dmdmlgv qpixjf 80 3th 94449
4004 m bgglt civknxjj 34 8th 94047
2155 m jkihczo gcktwprr 62 5th 94581
14 m richards keith 42 4th 94112

8623 m osnzkufb tknkia 16 3th 94784
2402 s uwnrk slzbfp 64 3th 94702
3864 h bmvrgxy vbxsar 50 9th 94590
9411 s rzx woekhwainehb 88 6th 94976
3052 s cfrvuqhbbou ubfxosmtdgs 63 3th 94797
1932 h zfsvfnnsb isowirbu 55 3th 94986
6177 s yzn h 93 7th 94239

1303 m esdce iumfrwyad 54 2nd 94998
8034 m naj izvyg 99 3th 94736
2036 h lgtveorn qtqdysbbamns 1 1st 94630
5411 h grk fgg 20 3th 94516
6805 m lf falcxubfary 20 6th 94924
2254 m agxvf n 29 4th 94869
31 m leaves t 22 2nd 94223

3722 s gmtvnjrkc htrk 12 7th 94183

9203 h zhvwzg woaesviww 33 7th 94977
356 m skqosem tabbiaxszjqn 84 9th 94956
5123 m yfekff r 52 1st 94796
2047 m tmfbp zklpveme 98 1st 94206
3756 m bpiuzcogn tpxfcfp 32 3th 94850
7397 s lhl vbpf 32 7th 94588
101 m zghagi nhpkssfabzy 62 5th 94681
38 h tubman harriet 50 5th 95555

266 h aaeenb kbpfxvvyxhne 86 1st 94929
4638 m wu qoa 33 7th 94635
2057 m mhz hpcghjizfb 30 7th 94622
8857 h ppkhaf eui 65 4th 94017
7328 h yldeju mbfecpqtdog 44 4th 94946
5909 s ddccxbegbxs pazd 45 9th 94073
3219 m nobdww lccyikahop 25 2nd 94793
1272 s vpn gkncsrtzviv 85 4th 94517

643 s kqt easrrxtnxc 26 2nd 94055
3096 s alcgmrrq q 30 4th 94368
3028 s lovbn rykdsaabn 35 3th 94322
6103 s ucllxpyqlvf riovqtz 9 5th 94280
2995 h frjsgbgewqoo jvwuypn 9 8th 94888
5039 m dkkkk aklhevmz 46 4th 94482
1689 m xzmkvzuo kifjlbgbctw 7 4th 94129
7245 m dzkitd juas 25 6th 94012
46 h lovelace ada 56 5th 95123

6348 h vqqlf dujslpeeyky 62 9th 94128
4490 m fyqjifmnb omjrmksi 45 3th 94828
4786 h vvumelsfzelg zhvaqo 45 8th 94206
6255 s jtnaajhi ebqnawre 40 2nd 94953
4682 h ww kkyyyywobvb 50 3th 94355
1447 h lesspipdixz tfo 88 8th 94743
7936 h phroqpmnzpkb jtl 98 1st 94878
3579 s jxrnbnxpyng mrnmqiol 19 4th 94229

6445 h bom stjt 44 2nd 94574
1203 m sroypetxqo v 36 1st 94841
2366 h ecuci khppwfsxobd 80 9th 94277
672 h lbwgrjxuroop ynflyjkvnpa 49 9th 94947
1346 h sdybi couwdf 55 5th 94331
9328 m tewsxha e 36 6th 94372
5107 s shmfnujyb gcsmwuq 55 7th 94228
4925 m vbntoacvozh uue 44 3th 94288
3307 h maaxsb jafchphrj 76 8th 94075
483 h mqpm lysryqiwqiz 66 1st 94475
867 s yladaednntzl dwggluyymr 69 7th 94100
8991 h hhatr ci 44 7th 94460
3533 h js vecvlj 20 6th 94472

5876 s cswtomn y 85 4th 94822
9517 h vgkfhts zgppwqigjb 93 3th 94371
5898 h ufeu mli 64 6th 94135
5657 m nsgtxfrk adalozpxfhyr 7 7th 94651
40 m chavez cesar 57 5th 95112

7314 h nrajjzqxw njygptloffts 37 6th 94420
118 m pdamn pnaijxpleiec 91 3th 94911
8475 m ju bsjhulr 59 3th 94144
3769 s xalce ab 54 7th 94944
8899 m nck dwuedwxapl 9 6th 94076
2026 s xekqvkhu pohzqezjvij 50 9th 94091
8016 h vdjprvlyy ebudvkbabrg 0 1st 94624
5293 h svsgafeu woxx 9 3th 94050
638 s msogfk ww 20 9th 94256
6664 m suolvt vl 64 8th 94779
8642 m ys gs 67 3th 94850
2634 m htaxnth yocdlgenatuo 99 8th 94316
4380 s zccdz nahqowu 95 8th 94453
4446 m ab uwsukpb 12 3th 94450
2783 s pvmvaeyok zohyrrqk 16 3th 94503
4077 m ovltcsclhvnk ownruqiqgyoe 88 1st 94731
34 m morrison norman 71 7th 94771
23 s kate wilhelm 73 7th 94778

6217 s gkprdrsnx pn 21 6th 94386
9306 s spbddujhn qbkugoh 0 7th 94220
7120 s iwzwh rbjahmojk 88 1st 94611
4253 s rqxwrvxdget houpxiz 95 8th 94057
877 m kmwdfommor umduh 16 4th 94053
2318 m mggmqyjt ypnbfsmbxe 27 7th 94407
1175 m xxmofy blhy 24 8th 94024
3400 h zxbvldqosj f 57 6th 94076
5208 s bhxetnldxzp ynpkzcfufkb 36 8th 94848

3133 s snttpu ivevzpopbnq 93 7th 94493
1708 m yu whvyzpce 94 5th 94866
2705 m yu va 63 8th 94131
3375 m cxbe eennedzayvg 39 5th 94167
2887 m rbvwrcdggn ehimyxxbdq 28 6th 94508
5438 h lp gt 21 6th 94528
2611 h aazfnsoqh gnaaaaist 69 1st 94687
9834 m dbjiqik n 49 2nd 94498
11 s black mary 21 2nd 94221

3480 s kccyf mstuoqpzwxol 2 3th 94186
2036 m apefed nvaclxxkoyh 90 4th 94846
2872 h awoh puoyghm 78 5th 94397
1093 s tqumtyufpze tbieae 25 9th 94367
9584 h rxfnhepis mtqwjgjpgpx 8 4th 94780
7834 s zzhiliyhgcbp rztggrg 40 5th 94841
2942 h ykhi rivvnxzgwoth 49 5th 94779
2442 s fjldj x 50 4th 94554
1450 s iwrh fd 76 1st 94317

7174 h qykmptiq gnbwd 17 8th 94131
5761 m swj ewqze 84 9th 94766
5433 s imho p 66 9th 94287
3592 h dnztrxje ufbwa 85 3th 94348
5064 h jhtafm fvcjpjuuhsc 38 3th 94135
1134 m pkdmndv tqfx 59 1st 94173
3569 m rxoqauucz voeraornwdpe 50 6th 94707
7872 s ibd hisgdrrnw 47 8th 94701
42 s goldman emma 64 6th 94611
35 s anthony susanB 48 4th 94321

6917 s wik tnrvvce 15 5th 94925
1681 h ahysjg qr 25 7th 94124
8103 m jcqgaiatdmao vvo 56 8th 94110
9190 s eveiqxpuqc gam 59 6th 94995
1463 h hptstto bpwchj 26 7th 94665
4232 h xczyd inxob 91 7th 94990
7572 h drjufkf iis 81 9th 94837
868 m adcg fxlf 23 2nd 94712
4145 s dxcpizmnjb jlydpsqzm 86 5th 94102
2424 h entltg him 56 6th 94672

1986 s mllirytfbqi bxw 41 7th 94607
7490 m idzxwbdzmypx xjgixh 86 6th 94403
4137 h ca n 51 6th 94141
6612 s ueahmy qcktislc 46 9th 94554
9508 m lyexkpueujhs vpb 22 4th 94944
1438 h vncdpxshefte odnhxiz 14 4th 94595

7886 m fviyshp l 1 6th 94301
3873 m hmvwtmhyoc xs 18 9th 94554
4879 m ctnq xac 5 8th 94216
1121 h pplxbabuu sksou 48 6th 94406
1275 h jqr irzrm 32 2nd 94146
8890 m uhykkrjxylyq dchsepkiit 15 8th 94789
4424 m cgjhpwehit zdaso 51 7th 94050
8201 m brwo fkvdgdkn 81 3th 94012
8108 m cnnjqobopipd ipiiglhxy 81 2nd 94788
2812 s pgsr teuz 62 1st 94518
9539 h bjksbf sbf 27 4th 94188
5772 h tfssv ehkqla 23 6th 94001
3510 s awhbihyoc yxw 69 5th 94622

8662 s mnr o 98 8th 94981
2751 m wrhn uhwwq 9 4th 94743
8315 h abe bs 5 7th 94319
6939 s yos uhre 64 8th 94429
9582 s xjjcjdx tmypeh 43 1st 94140
1618 h pjgonnhg qgbtz 40 2nd 94002
7623 m fgemfunp jdrtdlfeov 90 9th 94956

4575 s suhsdshv qbpznrnk 72 8th 94802
8972 s cwi djdxs 49 8th 94122
7777 m srinoria w 86 1st 94502
4792 m ak tyrzfdjckmx 78 5th 94138
197 s asunmf m 23 9th 94916
3753 m zvzkunlxdlp l 65 1st 94384
9758 s toosalb afdvrswpyi 88 2nd 94686
4394 s opmehoyxmrey orvjuqgjzncb 5 6th 94147
5446 s wkdokj svoagfjnoyq 38 4th 94487
1004 m pqxutg uitkog 54 5th 94132
03 s simone nina 27 2nd 94112

4387 s ezkvixatteq dlv 6 5th 94019
7493 m wxn nyovmdco 99 1st 94240
5824 h pimklqcy ummjzrdbzrmk 90 7th 94992
4919 m eiffhzlskw jieatup 88 8th 94578
7558 m zgwhhstavjwp vbqq 33 1st 94171
4715 h al ytjg 79 5th 94262
7668 h kvoxueptieyi y 38 5th 94826
8295 m lodilum ajft 68 3th 94436
2123 s halga shobx 53 4th 94216
4421 h vvh lnfmsqdmr 14 5th 94310
8546 m vffgzqfoq fyygfgovf 17 6th 94124
595 m gkophenb raxemglgn 40 2nd 94361
2530 m canveen hwxvupqle 61 4th 94440

8986 m lac qfbnijtqsku 91 4th 94470
4184 h zkoqri bydylaspp 31 4th 94340
8125 m pvsoamvm eub 4 4th 94975
6082 m spokhrm mrpgdscrnfbj 1 1st 94376
9872 s rwd edhfxzrjjekg 9 6th 94661
1489 m ikspzpztm vzkex 96 7th 94607
9442 h vqfumhsvucca erdyupekuoru 32 3th 94524
1473 h cyd gauc 86 9th 94517
09 m prine john 35 3rd 94321
07 s marley rita 26 2nd 94212
06 m marley bob 22 2nd 94112

8461 s lbpqo vjgdmhei 58 9th 94038
9364 s qyrc ykwnaos 4 3th 94871
6727 m amqgshj rsnjtaw 23 4th 94252
2298 h jrwlqudav kfsqpzifhuxd 55 7th 94813
2144 s an cgmpds 9 8th 94162
170 s gwopqkocvvt yqrmqidh 31 4th 94112
1249 h vcz offajfsjgz 50 7th 94877
2120 s spfs f 48 9th 94946
6584 h wjakc itretogef 81 2nd 94204
9449 m lwyiyqfzqx ejeass 24 5th 94209
2398 m auqrezm oetqrzszaejq 81 6th 94539
6416 m ifeiskav xvepibehib 52 7th 94477
9531 m znmpbtpt kdrnptw 44 3th 94793
2551 s gtyunz nuozigjlhhlz 17 3th 94144

2527 m kwytirlpvzlm lq 35 5th 94396
6454 h a gs 73 8th 94802
695 m qhlji qajtf 66 9th 94746
9476 s uejucngt ikwmbbp 54 6th 94746
7648 h njwsuhtux yyrxdu 73 5th 94336
8369 h a ntfx 84 1st 94179
1690 m zibi y 74 1st 94486
4055 h pzt cn 10 8th 94039
7653 s irdglamxny ebjexaij 52 3th 94259
6116 s a gtvf 64 7th 94492
9615 h hfatoqcm nv 81 1st 94093
9159 m ebwmt qpwzvzr 65 1st 94451
5427 m a qdhjy 5 2nd 94722
7184 s pqa a 19 5th 94512
1206 h a nykcwc 73 9th 94205
2283 s pm iduapniizsa 40 5th 94470
5894 m a gfykzgpdvzd 31 1st 94188
2614 m a nvodmkpoz 12 9th 94100
19 h mitchell joni 40 4th 94444

7072 m b vixfpvilkbi 41 5th 94542
3565 s usapnbx rkelqwuikhpl 25 5th 94487
9919 h hwdhgrr qu 97 7th 94761
6999 h ljjxih fnnkqaczmmai 5 3th 94422
1271 h clrg anexszxsd 29 9th 94971
6337 m yqvtile n 2 9th 94390
8730 h lgojmmztxxmy thlesbymaob 27 7th 94339
7957 h hbbld agxgyr 51 8th 94335
3833 h rawuddpf kdjluwc 10 4th 94126
4853 h eb odurd 25 6th 94242
7521 m ecsvmx zfvqkgtrlgh 27 6th 94145
1841 m b wkqhw 54 8th 94631
9171 s fljywfez llamhlwoh 45 6th 94240
5948 h kle lxcbppn 33 3th 94894
2615 m qtondkqxsln zpwcir 39 3th 94500
2204 m rivmjmuy odat 61 6th 94604
49 m einstein albert 54 5th 94113
18 m springstein bruce 45 4th 94323
15 m jagger mick 41 4th 95115

8753 m xgyngwnskr mklfdnoi 66 8th 94005
4718 h nkxzynxzdne u 34 6th 94920
6324 s c uvzi 85 7th 94721
3612 h qbgoi jcoyhuc 45 5th 94320
4720 h pjzitlewf fsmzzjy 81 8th 94675
3873 m vxf hro 71 1st 94623
126 h c fbbdqvmnudbz 44 2nd 94947
668 s xfhqnolm ytsoevulz 39 5th 94659
4731 m c cnnprixyah 38 1st 94573
6500 h ldwrmzrkcw drfzogzzx 98 9th 94377
5197 h c tijwihesv 14 6th 94105
6411 s eswhe rhbkhanpg 6 2nd 94649
5605 h jhg qkfhjjjxxxl 0 3th 94465

8312 s d flfejssdpip 6 9th 94225
6485 m mrhfzwg wh 44 7th 94037
2411 h zyhblprp wvanlhfmolm 54 4th 94629
7483 h d v 6 4th 94576
6383 h mpnqx qmxzpbcenysn 46 5th 94994
914 h eggzdlm bdgfnrxfzs 37 7th 94298
5309 s pcfagenytrc fcpuyd 18 8th 94210
4369 h okzi fzviampzqu 5 1st 94542
4887 m d rvhsrq 31 9th 94440
8112 h ed iepjod 5 7th 94613
9990 s fvh cpctinsgkc 68 8th 94575
*/