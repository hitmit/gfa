 $(document).ready(function() {
         $('.owl-carousel').owlCarousel({
            loop:true,
            margin:10,
            autoHeight:true,
            responsiveClass:true,
            responsive:{
                0:{
                    items:1,
                    nav:false
                },
                600:{
                    items:1,
                    nav:false
                },
                1000:{
                    items:1,
                    nav:false,
                    loop:false
                }
            }
        });

    var $accordion = $('.accordion.career-person');
    $accordion.click(function () {
        
      $(this).toggleClass('open');

    });

    //force the username on the inital logintoboggan page
    $(".page-toboggan #edit-name").val("gils");
    $("").hide();


});
