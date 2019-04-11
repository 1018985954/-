$(document).ready(function(){
    var username = new Input('#username');
    var valid = username.validator.is_valid();
    console.log('valid:',valid);
})
