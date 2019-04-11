$(document).ready(function(){

    window.Input = function(selector){
        var $ele,
        rule = {},
        me = this;

        this.load_validator = function(){
            var val = this.get_val();
            this.validator = new Validator(val,rule);
        }

        this.get_val = function(){
            return $ele.val();
        }

        function init(){
            find_ele();
            parse_rule();
            me.load_validator();
        }

        function find_ele(){
            if(selector instanceof jQuery) $ele=selector;
            else $ele = $(selector);
        } 
        function parse_rule(){
            var rule_string = $ele.data('rule');
            if(!rule_string) return;

            var rule_arr = rule_string.split('|');
            for (var i = 0; i< rule_arr.length;i++){
                var item_str = rule_arr[i];
                var item_arr = item_str.split(':');
                rule[item_arr[0]] = JSON.parse(item_arr[1]);
            }
        }
        
    }
})