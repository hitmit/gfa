jQuery(document).ready(function ($) {
  
 

    window.sr = ScrollReveal();
   animating();





  /* Boostrap accordian id creation for accordion tabs*/


  $(".accordion-tabs ul li").each(function (i) {
    var currentItem = $(this);
    var currentId = "accordion-tab-" + i;
    var currentCollapseID = "tab" + i;
    var currentHref = "#tab" + i;
    currentItem.attr("id", currentId);
    currentItem.find("h5 a").attr("href", currentHref);
    currentItem.find(".collapse").attr("id", currentCollapseID);
  });

  $(".three-col-accordion").each(function (i) {
    var currentID = "three-col-accordion-" + i;
    $(this).attr("id", currentID);;
  });


  /* var currentDescription = $('.three-col-accordion .three-col-accordion-item:eq(0) .card-text').html();
   $('.three-col-accordion .three-col-accordion-item:eq(0) .card-block').addClass("active");
   $('.three-col-accordion .current-description').fadeOut(700, function() {
             $(this).html(currentDescription).fadeIn(700);
           });*/
  $('.three-col-accordion .three-col-accordion-item .card-block').on('click', function (e) {
    var currentElement = $(this);
    var currentAccordionID = currentElement.parents(".three-col-accordion").attr('id');
    console.log(currentAccordionID);
    $(".three-col-accordion .current-description").hide();

    var currentAccordion = $("#" + currentAccordionID);

    $('.three-col-accordion-item .card-block').removeClass("active");
    $('.three-col-accordion').removeClass("current-accordion");
    currentElement.addClass("active");
    currentAccordion.addClass("current-accordion");

    var descriptionElement = currentElement.find('.card-text');

    if ((descriptionElement.children().length)) {
      /* currentElement.parents('.three-col-accordion').find('.current-description').slideDown("slow", function(){
         $(this).html(descriptionElement.html());
       });*/
      currentElement.parents('.three-col-accordion').find('.current-description').html(descriptionElement.html());
      currentElement.parents('.three-col-accordion').find('.current-description').show();


    }


  });


  $( "#searchtoggle" ).click(function() {
      //$("#searchform").show("slide", { direction: "left" }, 1000);
      $("#searchform").fadeIn(100);
      return false;
  });


$('#searchform_close').on("click", function(){
   //$("#searchform").hide("slide", { direction: "right" }, 1000);
   $("#searchform").fadeOut(100);
   return false;
});




  /* Custom Gallery Slider - slick Slider */


  var $sliderStatus = $('.slider-active');
  var $slickElement = $('#gallery-slideshow');


  $slickElement.on("init", function (event, slick) {
    var i = 1;
    $sliderStatus.text(i + '/' + slick.slideCount);
  });


  $slickElement.slick({
    centerPadding: "160px",
    dots: false,
    arrows: true,
    centerMode: true,
    focusOnSelect: true,
    responsive: [
      {
        breakpoint: 992,
        settings: {
          arrows: true,
          centerMode: true,
          centerPadding: "80px",
        }
      },
      {
        breakpoint: 768,
        settings: {
          arrows: true,
          centerMode: false,
          centerPadding: "0",
        }
      },
      {
        breakpoint: 480,
        settings: {
          arrows: true,
          centerMode: false,
          centerPadding: "0",
        }
      }
    ]
  });


  $slickElement.on("afterChange", function (event, slick, currentSlide) {
    //console.log(currentSlide);
    var i = (currentSlide ? currentSlide : 0) + 1;
    $sliderStatus.text(i + '/' + slick.slideCount);
  });


  if (/Mobi/.test(navigator.userAgent)) {
    updateSlider();
  }


  /* dynamic columns - set height based on the max height of colums */
  setDynamicColHeight();

  $(window).resize(setDynamicColHeight);

  // $(".search_button").click(function () {
  //   var $lefty = $(".search-box-inner");
  //   $lefty.animate({
  //     left: parseInt($lefty.css('right'), 0) == 10 ?
  //       -$lefty.outerWidth() : 0,
  //     'opacity': '1',
  //   });
  // });
  $(".search-box-inner").hide();
    $(".search_button").click(function () {
        var $lefty = $(".search-box-inner");
        $lefty.toggle();
    });


  $(".banner .video-js.vjs-16-9").addClass("removewidth");

  $('.play-btn').not('.resources .video-js .vjs-big-play-button').click(function () {
    //console.log("in click event");
    $(".banner .video-js.vjs-16-9").removeClass("removewidth");

    var $videoElement = $(this).parents('.media-player').find('video');
    $(this).parents('.banner').addClass('active');
    $videoElement.addClass('show');
    $videoElement.trigger('play');

    $(".banner.active .card-block").css("display", "none");

  });


  /* hide team badge if first alert is not slected */
  $('.team-item').each(function () {
    if ($(this).find('.first-alert').hasClass('show-alert')) {
      $(this).find('.badge').show();
    }
  });



  var firstFilter = getQueryString('tid_1');
  var secondFilter = getQueryString('tid');

  if (firstFilter == 4) {
    $('.resources #edit-tid-wrapper  #edit-tid-2, .resources #edit-tid-wrapper #edit-tid-all').hide();
    $('.resources #edit-tid-1-wrapper').css('display', 'block');
  }


  if (firstFilter == 2 && secondFilter == 2) {
    $('.resources #edit-tid-2-wrapper').css('display', 'block');
    $('.resources #edit-tid-1-wrapper').addClass('cells-tab-active');
    $('.team-item .badge').hasClass('clientlink-subscription-management').hide();
  }

  if (secondFilter == 2) {
    // $('.card.akriti-bhatia').parents('.team-item').children('.badge').css('border','solid 1px red');
    $('.card.akriti-bhatia').parents('.team-item').children('.badge').addClass('hide-badge');
    $('.view-our-team').addClass('cells-team');

  }

  if (secondFilter == 4) {
    $('.card.julie').parents('.team-item').children('.badge').addClass('hide-badge');
  }

  if (firstFilter == 5) {
    $('.resources #edit-tid-wrapper').css('visibility', 'hidden');
    $('.resources-container .row.resources-filter').css('height', '90px');
  }


  /* magnific pop up for resources type video */
  //videojs.options.flash.swf = "video-js.swf";
  $('.open-popup-link').magnificPopup({
    type: 'inline',
    midClick: true
  });

  $('.resources .open-popup-link').on('click', function () {
    console.log("in click videojs");
    videojs('#resources_video').play();
  })

  function body_sizer() {
    var bodyHeight = $(window).height();
    var headerHeight = $('#header-mck').height();
    var videoHeight = bodyHeight - headerHeight;
    $(".background-video-wrapper .media-video").height(videoHeight);
  }


  function setDynamicColHeight() {

    $(".card-module").each(function () {
      var maxHeight = 0;
      var currentSection = $(this);
      currentSection.find(".card-module-item").css("height", "auto");
      currentSection.find(".card-module-item").each(function () {
        if ($(this).height() > maxHeight) {
          maxHeight = $(this).height();
        }
      });
      currentSection.find('.card-module-item').height(maxHeight);
    });

  }


  function updateSlider() {
    // $('#gallery-slideshow').addClass('gallery-slick-mob');
    var arrowOffsetTop = $('.slick-slide img').height() + 50;
    var sliderCounterTop = $('.slick-slide img').height() + 40;
    $('.slick-prev, .slick-next').css('top', arrowOffsetTop);
    $('#gallery-slideshow .slider-active').css('top', sliderCounterTop);

  }

  body_sizer();
  $(window).resize(body_sizer);
  // setupScrollReveal($('div.region.region-content').find('.row'));
});

function getQueryString(field, url) {
  var href = url ? url : window.location.href;
  var reg = new RegExp('[?&]' + field + '=([^&#]*)', 'i');
  var string = reg.exec(href);
  return string ? string[1] : null;
};
function animating(){
  $ = jQuery;

    // if ($(window).width() > 768) {
      
     

  $('.background-video-wrapper .card-block,.banner .card-block').addClass('hidden').waypoint({handler: function() {$(this.element).addClass("visible animated fadeIn")},offset: '90%'});

  $('.four-col-card').addClass('hidden').waypoint({handler: function() {$(this.element).addClass("visible animated fadeIn")},offset: '90%'});
  $('.two-col-event .bg,.two-col-event .content-wrapper,.two-col-event .date').addClass('hidden').waypoint({handler: function() {$(this.element).addClass("visible animated fadeIn")},offset: '90%'});

  $('.three-col-team .btn,.card-module .center-block').addClass('hidden').waypoint({handler: function() {$(this.element).addClass("visible animated slideInUp")},offset: '90%'});

  sr.reveal('.card-item', { duration: 1500,easing: 'cubic-bezier(0.6, 0.2, 0.1, 1)',mobile: false,useDelay: 'once' }, 700);
  $('.two-col-overview:nth-child(odd)').addClass('hidden').waypoint({handler: function() {$(this.element).addClass("visible animated slideInLeft")},offset: '90%'});
  $('.two-col-overview:nth-child(even)').addClass('hidden').waypoint({handler: function() {$(this.element).addClass("visible animated slideInRight")},offset: '90%'});


    sr.reveal('.two-up .card,.three-col-accordion-item,.prespectives-resources .card-module .card,.help-item', { duration: 1200,easing: 'cubic-bezier(0.6, 0.2, 0.1, 1)',mobile: false,useDelay: 'once',delay:'200'  },400);
    




      


}
function checkOffset() {
    if($('.promo-bar .col-12').offset().top + $('.promo-bar .col-12').height() >= $('.mck-footer').offset().top - 60)
        $('.promo-bar .col-12').css('position', 'absolute');
    if($(document).scrollTop() + window.innerHeight < $('.mck-footer').offset().top)
        $('.promo-bar .col-12').css('position', 'fixed'); 
}
jQuery(document).scroll(function() {
    checkOffset();
});


// function setupScrollReveal(nodeList) {
//   var $=jQuery;
//   nodeList.each(function(index,item){
    
//     if($(this).hasClass("card-module")){
//       window.sr.reveal($(this).find('.py-1'));
//     }else{
//       window.sr.reveal($(this));
//     }
//   });
  
// }