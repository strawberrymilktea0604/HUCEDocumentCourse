function check(){
         
    if (txtEmail.value==""){
        alert("email chưa được nhập !");
        txtEmail.focus();
        return false;
    }
    if (txtPass.value==""){
        alert("Pass chưa được nhập !");
        txtPass.focus();
        return false;
    }  
  
    r = /\w\@\w/   
    if (r.test(txtEmail.value)==false){
        alert("Email sai định dạng !");
        txtEmail.focus();
        return false;
        }             
} 