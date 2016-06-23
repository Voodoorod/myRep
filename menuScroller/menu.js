$(function(){

    var header_height = 40; //есть шапка
    var header_hidden = -10;  //проскроллили ниже
    var menu = $('#menu'); // ID для меню
    var top = $(this).scrollTop();

    if(top > header_height)
        menu.css('top', 40);

    $(window).scroll(function()
    {
        top = $(this).scrollTop();

        if(top + header_hidden < header_height)
            menu.css('top', (header_height - top));
        else
            menu.css('top', header_hidden);
    });
});
