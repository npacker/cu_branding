(function($) {
	$(document).ready(function() {
		$("#cu-search-form").submit(function(event) {
			var searchString = $("#cu-search-input").val();
			
			window.location = window.location.protocol + "//" + window.location.hostname + "/search/node/" + searchString;
			
			event.preventDefault();
		});
	});
})(jQuery);