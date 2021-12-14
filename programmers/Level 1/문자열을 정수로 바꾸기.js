function solution(s) {
    let siz = s.substring(0,1);
    let nes = s.substring(1,s.lentgh);
    return siz===('+') ? parseInt(nes) : parseInt(s);
}
