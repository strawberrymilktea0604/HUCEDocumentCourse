$(function() {
    let tmpDay = "";
    for (let i = 1; i < 32; i++) {
        tmpDay += `<option value="${i}">${i}</option>`
    }
    $('#selectDay').html(tmpDay)
    let tmpMonth = "";
    for (let i = 1; i < 13; i++) {
        tmpMonth += `<option value="${i}">${i}</option>`
    }
    $('#selectMonth').html(tmpMonth)
    let tmpYear = "";
    for (let i = 1940; i < 2000; i++) {
        tmpYear += `<option value="${i}">${i}</option>`
    }
    $('#selectYear').html(tmpYear)

})

function clearr() {
    $('#userName').val('')
    $('#pw1').val('')
    $('#rePw1').val('')
    $('#pw2').val('')
    $('#rePw2').val('')
    $('#chooseQ').val('')
    $('#anwser').val('')
    $('#fullName').val('')
    $('#email').val('')
    $('#addr').val('')
    $('#homePhone').val('')
    $('#cellPhone').val('')

}

function regiterr() {
    if (checkPass()) {

    }
}

function checkPass() {
    let check = true;
    checkInput()
    if (checkInput()) {
        if (!$('#email').val().match('/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/') && check) {
            alert("Email sai định dạng.")
            check = false;
        }
        if ($('#userName').val().length > 6 && $('#userName').val().length < 12 && check) {
            alert('User name from 6 to 12 character')
            check = false
        }
        if ($('#pw1').val().length > 6 && $('#pw1').val().length < 12 && check) {
            alert('Pass1 name from 6 to 12 character')
            check = false
        }
        if ($('#pw2').val().length > 6 && $('#pw2').val().length < 12 && check) {
            alert('Pass2 name from 6 to 12 character')
            check = false
        }
        if ($('#pw1').val() !== $('#rePw1').val() && check) {
            alert('Pass 1 không trùng re-pass1')
            check = false
        }
        if ($('#pw2').val() !== $('#rePw2').val() && check) {
            alert('Pass 2 không trùng re-pass2')
            check = false
        }
        if ($('#pw2').val() === $('#pw1').val() && check) {
            alert('Pass 1 phải khác Pass 2')
            check = false
        }

    }
    return check;
}

function checkInput() {
    let check = true;
    if ($('#userName').val().length == 0 && check) {
        alert("Bạn chưa nhập username")
        check = false;
    }
    if ($('#pw1').val().length == 0 && check) {
        alert("Bạn chưa nhập password1")
        check = false;
    }
    if ($('#rePw1').val().length == 0 && check) {
        alert("Bạn chưa nhập re-password1")
        check = false;
    }
    if ($('#pw2').val().length == 0 && check) {
        alert("Bạn chưa nhập password2")
        check = false;
    }
    if ($('#rePw2').val().length == 0 && check) {
        alert("Bạn chưa nhập re-password1")
        check = false;
    }

    if ($('#anwser').val().length == 0 && check) {
        alert("Bạn chưa nhập anwser")
        check = false;
    }
    if ($('#fullName').val().length == 0 && check) {
        alert("Bạn chưa nhập fullName")
        check = false;
    }
    if ($('#email').val().length == 0 && check) {
        alert("Bạn chưa nhập email")
        check = false;
    }
    if ($('#addr').val().length == 0 && check) {
        alert("Bạn chưa nhập addr")
        check = false;
    }
    if ($('#homePhone').val().length == 0 && check) {
        alert("Bạn chưa nhập homePhone")
        check = false;
    }
    if ($('#cellPhone').val().length == 0 && check) {
        alert("Bạn chưa nhập cellPhone")
        check = false;
    }
    if ($('#chooseQ').val() == 0 && check) {
        alert("Bạn phải chọn question")
        check = false;
    }
    return check;
}