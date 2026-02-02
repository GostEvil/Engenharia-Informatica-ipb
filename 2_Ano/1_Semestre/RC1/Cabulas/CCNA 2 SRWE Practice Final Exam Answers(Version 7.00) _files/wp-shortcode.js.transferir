jQuery(document).ready(function($){
	// Toggles
	if ($('.wp_shortcodes_toggle').length) {
		$(".togglec").hide();
		$(".wps_togglet").click(function(){
		 $(this).toggleClass("toggleta").next(".togglec").slideToggle("normal");
		});
	 }

	 // Tabs
	if ($('.wp_shortcodes_tabs').length) {
		$('.wp_shortcodes_tabs').each(function() {
			var $this = $(this);
			$this.find('.tab_content').slice(1).hide();
			$this.find('ul.wps_tabs li:first').addClass('active');
			$this.find('ul.wps_tabs li a').click(function(e) {
				e.preventDefault();
				var $this_a = $(this);
				var $tab = $this.find('#'+$this_a.data('tab'));
				if (! $tab.is(':visible')) {
					$this.find('.tab_content').hide();
					$this_a.parent().addClass('active').siblings().removeClass('active');
					$tab.fadeIn(600);
				}
			});
		});
	}

	if ($('.wp_shortcodes_tooltip').length) {
		$('.wp_shortcodes_tooltip').each(function(index, el) {
			var $this = $(this),
					ttgravity = $this.data('gravity'),
					ttfade = Boolean($this.data('fade'));
			$this.tipsy({gravity: ttgravity, fade: ttfade});
		});
	}
});
