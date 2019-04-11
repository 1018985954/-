$(document).ready(function(){
    
    window.Validator = function(val,rule){
        
        this.is_valid = function(){
            var key;
            for(key in rule){
                var result = this['validate_'+ key ]();
                if(!result) return false;
            }
            return true;
        }

        this.validate_maxlength = function (){
            this.validate_pre_length();
            return val.length <= rule.maxlength;
        }
        this.validate_minlength= function (){
            this.validate_pre_length();
            return val.length >= rule.minlength;
        }
        
        this.validate_pre_length= function(){
            val = val.toString ();
        }

        this.validate_pattern = function (){
            var reg = new RegExp(rule.pattern);
            return reg.test(val);
        }
        
        this.validate_numeric = function (){
            return $.isNumeric(val);
        }

        this.validate_nullable = function (){
            var real = $.trim(val);
            if(!real && real !== 0) return false;
            return true;
        }
    } 
    
})
